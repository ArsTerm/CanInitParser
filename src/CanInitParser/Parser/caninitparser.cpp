#include "caninitparser.h"
#include "../caninitlexer.h"
#include "binexprnode.h"
#include "caninitnode.h"
#include "definitionnode.h"
#include "funccallnode.h"
#include "funcdefnode.h"
#include "idnode.h"
#include "indexaccessnode.h"
#include "numbernode.h"
#include "parsenode.h"
#include "structaccessnode.h"
#include <cassert>

#include <iostream>

using namespace ciparser;

CanInitParser::CanInitParser(std::unique_ptr<CanInitLexer>&& lexer)
    : lexer(std::move(lexer))
{
    updateToken();
}

ParseNode* CanInitParser::parse()
{
    auto result = new CanInitNode;
    while (true) {
        auto n = parse_p();
        if (!n)
            break;
        result->appendChildren(n);
    }
    return result;
}

void CanInitParser::updateToken()
{
    prev = std::move(t);
    t = lexer->nextToken();
}

void CanInitParser::pushBracket()
{
    Token t;
    t.type = TType::LParen;
    stackOperators.push(OperationInfo(t, true));
}

void CanInitParser::parseStack()
{
    parseStack(stackNodes, stackOperators);
}

void CanInitParser::parseStack(
        std::stack<ParseNode*>& n, std::stack<OperationInfo>& op)
{
    auto opn = std::move(op.top());
    op.pop();
    if (opn.unary) {
        auto node = n.top();
        n.pop();
        n.push(parse_p(opn.t, node));
    } else {
        auto r = n.top();
        n.pop();
        auto l = n.top();
        n.pop();
        n.push(parse_p(opn.t, l, r));
    }
}

void CanInitParser::offloadAll()
{
    offloadAll(stackNodes, stackOperators);
}

void CanInitParser::offloadAll(
        std::stack<ParseNode*>& n, std::stack<OperationInfo>& op)
{
    while (op.size() > 0 && op.top().t.type != TType::Eof) {
        parseStack(n, op);
    }
}

void CanInitParser::offloadStack(int priority)
{
    std::cerr << "Begin offload\n";
    offloadStack(stackNodes, stackOperators, priority);
    std::cerr << "End offload"
              << ", node size: " << stackNodes.size() << '\n';
}

void CanInitParser::offloadStack(
        std::stack<ParseNode*>& n, std::stack<OperationInfo>& op, int priority)
{
    if (op.size() == 0)
        return;
    std::cerr << "Operator on top: " << std::string(op.top().t)
              << ", node size: " << n.size() << '\n';
    while (op.size() > 0 && op.top().t.type != TType::Eof
           && op.top().t.type != TType::LParen
           && op.top().t.type != TType::LSquare
           && operatorPriority(op.top().t.type, op.top().unary) <= priority) {
        parseStack(n, op);
    }
}

bool CanInitParser::offloadBracket()
{
    offloadUntil(TType::LParen);
    if (stackNodes.size() > 0) {
        std::cerr << "Node:\n" << stackNodes.top()->toJson(0) << '\n';
    }
    if (!stackOperators.empty()
        && stackOperators.top().t.type == TType::LParen) {
        stackOperators.pop();
        return true;
    }
    return false;
}

void CanInitParser::offloadUntil(
        std::stack<ParseNode*>& n, std::stack<OperationInfo>& op, TType type)
{
    while (!op.empty() && op.top().t.type != type) {
        parseStack(n, op);
    }
}

void CanInitParser::offloadUntil(TType type)
{
    offloadUntil(stackNodes, stackOperators, type);
}

ParseNode* CanInitParser::parse_p()
{
    struct _Tmp {
        _Tmp(Token& t) : t(t)
        {
            std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        ~_Tmp()
        {
            std::cerr << "End " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        Token& t;
    } _(t);

    while (t.type == TType::LineFeed)
        updateToken();
    switch (t.type) {
    case TType::DefineKw: {
        auto n = parseDefinition();
        assert(stackOperators.size() == 0);
        return n;
    }
    case TType::Id:
        return parseId();
    case TType::Eof:
        return nullptr;
    default:
        std::cerr << "Undefined token: " << std::string(t) << '\n';
        assert(false);
        return nullptr;
    }
}

ParseNode*
CanInitParser::parse_p(const Token& operation, ParseNode* l, ParseNode* r)
{
    switch (operation.type) {
    case TType::Minus:
    case TType::Percent:
    case TType::Asterisk:
    case TType::Assign:
    case TType::And:
    case TType::Plus:
    case TType::AndLogic:
    case TType::OrLogic:
    case TType::Or:
    case TType::Xor:
    case TType::Equal:
    case TType::NotEqual:
    case TType::LSlash:
        return parseBinExpr(l, r, operation);
    case TType::Dot:
        return parseStructAccess(l, r);
    case TType::LSquare:
        return parseIndexAccess(l, r);
    default:
        assert(false);
        return nullptr;
    }
}

ParseNode* CanInitParser::parse_p(const Token& operation, ParseNode* n)
{
    switch (operation.type) {
    default:
        assert(false);
        return nullptr;
    }
}

constexpr int CanInitParser::operatorPriority(TType type, bool unary)
{
    switch (type) {
    case TType::Eof:
        return 0;
    case TType::LParen:
    case TType::Dot:
    case TType::LSquare:
        return 2;
    case TType::Increment:
    case TType::Decrement:
        return unary ? 2 : 3;
    case TType::Exclamation:
    case TType::Tilda:
        return 3;
    case TType::Asterisk:
        return unary ? 3 : 5;
    case TType::LSlash:
    case TType::Percent:
        return 5;
    case TType::Plus:
    case TType::Minus:
        return 6;
    case TType::RShift:
    case TType::LShift:
        return 7;
    case TType::LTriangle:
    case TType::RTriangle:
    case TType::LessOrEq:
    case TType::MoreOrEq:
        return 8;
    case TType::Equal:
    case TType::NotEqual:
        return 10;
    case TType::And:
        return unary ? 3 : 11;
    case TType::Xor:
        return 12;
    case TType::Or:
        return 13;
    case TType::AndLogic:
        return 14;
    case TType::OrLogic:
        return 15;
    case TType::Assign:
        return 16;
    case TType::Comma:
        return 17;
    default:
        break;
    }
    assert(false);
    return 0;
}

bool CanInitParser::isBeginExpression(TType t)
{
    switch (t) {
    case TType::Id:
    case TType::Number:
    case TType::LParen:
        return true;
    default:
        return false;
    }
}

bool CanInitParser::isFunctionDefinition() const
{
    auto const& next = lexer->peek();
    if ((t.type == TType::Id && next.type == TType::LParen)
        && (t.line == next.line)
        && (t.charPosInLine + t.data.size()) == next.charPosInLine)
        return true;
    else
        return false;
}

DefinitionNode* CanInitParser::parseDefinition()
{
    struct _Tmp {
        _Tmp(Token& t) : t(t)
        {
            std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        ~_Tmp()
        {
            std::cerr << "End " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        Token& t;
    } _(t);

    auto def = std::move(t);
    assert(def.type == TType::DefineKw);
    updateToken();
    if (isFunctionDefinition()) {
        auto f = parseFuncDef();
        auto expr = parseExpression();
        return new DefinitionNode(f, expr);
    } else {
        auto id = std::move(t);
        updateToken();
        if (t.type == TType::LineFeed)
            return new DefinitionNode(std::move(id));

        auto expr = parseExpression();
        return new DefinitionNode(std::move(id), expr);
    }
}

FuncDefNode* CanInitParser::parseFuncDef()
{
    struct _Tmp {
        _Tmp(Token& t) : t(t)
        {
            std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        ~_Tmp()
        {
            std::cerr << "End " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        Token& t;
    } _(t);

    auto id = std::move(t);
    updateToken();
    auto lp = std::move(t);
    assert(lp.type == TType::LParen);
    updateToken();
    std::vector<std::string> params;
    while (true) {
        assert(t.type == TType::Id);
        params.emplace_back(std::move(t.data));
        updateToken();
        if (t.type == TType::RParen)
            break;
        assert(t.type == TType::Comma);
        updateToken();
    }

    auto rp = std::move(t);

    assert(rp.type == TType::RParen);

    updateToken();

    return new FuncDefNode(id, std::move(params));
}

ParseNode* CanInitParser::parseExpression(TType endToken)
{
    struct _Tmp {
        _Tmp(Token& t) : t(t)
        {
            std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        ~_Tmp()
        {
            std::cerr << "End " << __FUNCTION__ << ": " << std::string(t)
                      << std::endl;
        }
        Token& t;
    } _(t);

    while (t.type != TType::LineFeed && t.type != endToken) {
        switch (t.type) {
        case TType::LParen: {
            pushBracket();
            updateToken();
        } break;
        case TType::Id:
            if (lexer->peek().type == TType::LParen) {
                stackNodes.push(parseFuncCall());
                //                return parseFuncCall();
                //                stackNodes.push(parseId());
                //                offloadStack(operatorPriority(TType::LParen));
                //                stackOperators.emplace(t, false);
                //                updateToken();
            } else {
                stackNodes.push(parseId());
            }
            break;
        case TType::Number:
            stackNodes.push(parseNumber());
            break;
        case TType::Dot:
            offloadStack(operatorPriority(TType::Dot));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::LSquare:
            offloadStack(operatorPriority(TType::LSquare));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Plus:
            offloadStack(operatorPriority(t.type));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Minus:
            offloadStack(operatorPriority(t.type));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::And:
            if (prev == stackOperators.top().t && !stackOperators.top().unary) {
                offloadStack(operatorPriority(TType::And, true));
                stackOperators.emplace(t, true);
            } else {
                offloadStack(operatorPriority(TType::And, false));
                stackOperators.emplace(t, false);
            }
            updateToken();
            break;
        case TType::Or:
            offloadStack(operatorPriority(t.type));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::AndLogic:
            offloadStack(operatorPriority(TType::AndLogic));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::OrLogic:
            offloadStack(operatorPriority(TType::OrLogic));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Xor:
            offloadStack(operatorPriority(TType::Xor));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::LSlash:
            offloadStack(operatorPriority(TType::LSlash));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Asterisk:
            if (prev == stackOperators.top().t && !stackOperators.top().unary) {
                offloadStack(operatorPriority(TType::Asterisk, true));
                stackOperators.emplace(t, true);
            } else {
                offloadStack(operatorPriority(TType::Asterisk, false));
                stackOperators.emplace(t, false);
            }
            updateToken();
            break;
        case TType::LTriangle:
            offloadStack(operatorPriority(TType::LTriangle));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::RTriangle:
            offloadStack(operatorPriority(TType::RTriangle));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::LessOrEq:
            offloadStack(operatorPriority(TType::LessOrEq));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::MoreOrEq:
            offloadStack(operatorPriority(TType::MoreOrEq));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::NotEqual:
            offloadStack(operatorPriority(TType::NotEqual));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Equal:
            offloadStack(operatorPriority(TType::Equal));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Exclamation:
            offloadStack(operatorPriority(TType::Exclamation, true));
            stackOperators.emplace(t, true);
            updateToken();
            break;
        case TType::RSquare:
            offloadUntil(TType::LSquare);
            parseStack();
            updateToken();
            break;
        case TType::RParen:
            if (!offloadBracket()) {
                if (stackNodes.size() > 1)
                    offloadAll();
                auto node = stackNodes.top();
                stackNodes.pop();
                return node;
            }
            updateToken();
            break;
        case TType::Comma:
            offloadStack(operatorPriority(TType::Comma));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::Increment: {
            auto const& next = lexer->peek();
            if (next.type == TType::Id
                && next.charPosInLine == t.charPosInLine + t.data.size()) {
                offloadStack(operatorPriority(TType::Increment, true));
            } else
                offloadStack(operatorPriority(TType::Increment, false));
            stackOperators.emplace(t, true);
            updateToken();
        } break;
        case TType::Decrement: {
            auto const& next = lexer->peek();
            if (next.type == TType::Id
                && next.charPosInLine == t.charPosInLine + t.data.size()) {
                offloadStack(operatorPriority(TType::Decrement, true));
            } else
                offloadStack(operatorPriority(TType::Decrement, false));
            stackOperators.emplace(t, true);
            updateToken();
        } break;
        default:
            std::cerr << "Undefined expression token: " << std::string(t)
                      << '\n';
            assert(false);
            return nullptr;
        }
    }
    if (stackNodes.size() > 1)
        offloadAll();
    std::cerr << "nodes size: " << stackNodes.size() << '\n';
    assert(stackNodes.size() == 1);
    auto node = stackNodes.top();
    stackNodes.pop();
    return node;
}

NumberNode* CanInitParser::parseNumber()
{
    std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
              << std::endl;
    auto num = std::move(t);
    updateToken();
    std::cerr << "End " << __FUNCTION__ << ": " << std::string(t) << std::endl;
    return new NumberNode(std::move(num));
}

FuncCallNode* CanInitParser::parseFuncCall()
{
    auto id = t;
    updateToken();
    updateToken();
    std::vector<ParseNode*> args;
    while (true) {
        args.emplace_back(parseExpression(TType::Comma));
        if (t.type == TType::RParen)
            break;
        updateToken();
    }
    updateToken();
    // assert(t.type == TType::LineFeed || t.type == TType::Eof);
    return new FuncCallNode(std::move(id), std::move(args));
}

BinExprNode*
CanInitParser::parseBinExpr(ParseNode* l, ParseNode* r, Token const& delim)
{
    return new BinExprNode(l, r, std::move(delim));
}

IndexAccessNode* CanInitParser::parseIndexAccess(ParseNode* l, ParseNode* r)
{
    return new IndexAccessNode(l, r);
}

StructAccessNode* CanInitParser::parseStructAccess(ParseNode* l, ParseNode* r)
{
    return new StructAccessNode(r, l);
}

IdNode* CanInitParser::parseId()
{
    std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
              << std::endl;
    auto id = std::move(t);
    updateToken();
    std::cerr << "End " << __FUNCTION__ << ": " << std::string(t) << std::endl;
    return new IdNode(std::move(id));
}
