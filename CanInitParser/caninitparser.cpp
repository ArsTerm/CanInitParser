#include "caninitparser.h"
#include "binexprnode.h"
#include "caninitlexer.h"
#include "caninitnode.h"
#include "definitionnode.h"
#include "expressionnode.h"
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
    t.type = TType::Eof;
    stackOperators.push(OperationInfo(t));
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

void CanInitParser::offloadStack(int priority)
{
    std::cerr << "Begin offload\n";
    offloadStack(stackNodes, stackOperators, priority);
    std::cerr << "End offload\n"
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
           && operatorPriority(op.top().t.type, op.top().unary) <= priority) {
        parseStack(n, op);
    }
}

void CanInitParser::offloadBracket()
{
    while (stackOperators.size() > 0
           && stackOperators.top().t.type != TType::Eof) {
        parseStack();
    }
    stackOperators.pop();
}

void CanInitParser::offloadUntil(
        std::stack<ParseNode*>& n, std::stack<OperationInfo>& op, TType type)
{
    while (op.top().t.type != type) {
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
    case TType::LParen:
        return parseFuncCall(n);
    default:
        assert(false);
        return nullptr;
    }
}

/*constexpr*/ int CanInitParser::operatorPriority(TType type, bool unary)
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
    updateToken();
    if (isFunctionDefinition()) {
        auto f = parseFuncDef();
        auto expr = parseExpression();
        return new DefinitionNode(std::move(def), f, expr);
    } else {
        auto id = std::move(t);
        updateToken();
        auto expr = parseExpression();
        return new DefinitionNode(std::move(def), std::move(id), expr);
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
    updateToken();
    std::vector<Token> params;
    std::vector<Token> dots;
    while (true) {
        assert(t.type == TType::Id);
        params.emplace_back(std::move(t));
        updateToken();
        if (t.type == TType::RParen)
            break;
        assert(t.type == TType::Comma);
        dots.emplace_back(std::move(t));
        updateToken();
    }

    auto rp = std::move(t);

    assert(rp.type == TType::RParen);

    updateToken();

    return new FuncDefNode(
            std::move(id),
            std::move(params),
            std::move(dots),
            std::move(lp),
            std::move(rp));
}

ParseNode* CanInitParser::parseExpression()
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

    while (t.type != TType::LineFeed && t.type != TType::Eof) {
        switch (t.type) {
        case TType::LParen: {
            pushBracket();
            updateToken();
        } break;
        case TType::Id:
            if (lexer->peek().type == TType::LParen) {
                stackNodes.push(parseId());
                offloadStack(operatorPriority(TType::LParen));
                stackOperators.emplace(t, false);
                updateToken();
            } else {
                stackNodes.push(parseId());
            }
            break;
        case TType::Number:
            stackNodes.push(parseNumber());
            break;
        case TType::Dot:
            std::cerr << "next token: " << std::string(t) << '\n';
            offloadStack(operatorPriority(TType::Dot));
            std::cerr << "Offload end\n";
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
        case TType::Equal:
            offloadStack(operatorPriority(t.type));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        case TType::RSquare:
            offloadUntil(TType::LSquare);
            updateToken();
            break;
        case TType::RParen:
            offloadBracket();
            updateToken();
            break;
        case TType::Comma:
            offloadStack(operatorPriority(TType::Comma));
            stackOperators.emplace(t, false);
            updateToken();
            break;
        default:
            std::cerr << "Undefined expression token: " << std::string(t)
                      << '\n';
            assert(false);
            return nullptr;
        }
    }
    if (stackNodes.size() != 1)
        offloadStack(INT_MAX);
    std::cerr << "nodes size: " << stackNodes.size() << '\n';
    assert(stackNodes.size() == 1);
    return stackNodes.top();
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

FuncCallNode* CanInitParser::parseFuncCall(ParseNode* n)
{
    return nullptr;
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
    return new StructAccessNode(l, r);
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
