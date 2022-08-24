#include "caninitparser.h"
#include "binexprnode.h"
#include "caninitlexer.h"
#include "caninitnode.h"
#include "definitionnode.h"
#include "expressionnode.h"
#include "funccallnode.h"
#include "idnode.h"
#include "indexaccessnode.h"
#include "numbernode.h"
#include "parsenode.h"
#include "structaccessnode.h"
#include <cassert>

#include <iostream>

using namespace ciparser;

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
        lastExpr = nullptr;
        return n;
    }
    case TType::Id:
        return parseId();
    case TType::Eof:
        return nullptr;
    default:
        std::cerr << "Undefine token: " << std::string(t) << '\n';
        assert(false);
        return nullptr;
    }
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
        auto f = parseFuncCall();
        auto expr = parseExpression();
        return new DefinitionNode(std::move(def), f, expr);
    } else {
        auto id = std::move(t);
        updateToken();
        auto expr = parseExpression();
        return new DefinitionNode(std::move(def), std::move(id), expr);
    }
}

ExpressionNode* CanInitParser::parseExpression()
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

    switch (t.type) {
    case TType::LParen: {
        updateToken();
        lastExpr = parseExpression();
        std::cerr << "Exit bracket expr" << std::string(t) << "\n";
        updateToken();
        std::cerr << "Next: " << std::string(t) << '\n';
        return parseExpression();
    }
    case TType::Id: {
        if (isFunctionDefinition())
            lastExpr = new ExpressionNode(parseFuncCall());
        else
            lastExpr = new ExpressionNode(parseId());
        return parseExpression();
    }
    case TType::Number:
        lastExpr = new ExpressionNode(parseNumber());
        return parseExpression();
    case TType::Dot:
        lastExpr = new ExpressionNode(parseStructAccess());
        return parseExpression();
    case TType::LSquare:
        lastExpr = new ExpressionNode(parseIndexAccess());
        return parseExpression();
    case TType::Plus:
    case TType::Minus:
    case TType::And:
    case TType::Or:
    case TType::Equal:
        lastExpr = new ExpressionNode(parseBinExpr());
        return parseExpression();
    case TType::LineFeed:
    case TType::RSquare:
    case TType::RParen:
    case TType::DefineKw:
    case TType::Comma:
    case TType::Eof:
        return lastExpr;
    default:
        std::cerr << "Undefined expression token: " << std::string(t) << '\n';
        assert(false);
        return nullptr;
    }
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

IdNode* CanInitParser::parseId()
{
    std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
              << std::endl;
    auto id = std::move(t);
    updateToken();
    std::cerr << "End " << __FUNCTION__ << ": " << std::string(t) << std::endl;
    return new IdNode(std::move(id));
}

StructAccessNode* CanInitParser::parseStructAccess()
{
    std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
              << std::endl;
    auto dot = std::move(t);
    updateToken();
    auto id = std::move(t);
    updateToken();
    if (dot.type != TType::Dot || id.type != TType::Id)
        assert(false);
    std::cerr << "End " << __FUNCTION__ << ": " << std::string(t) << std::endl;
    return new StructAccessNode(lastExpr, std::move(id), std::move(dot));
}

IndexAccessNode* CanInitParser::parseIndexAccess()
{
    std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
              << std::endl;
    auto lp = std::move(t);
    auto obj = lastExpr;
    updateToken();
    auto expr = parseExpression();
    auto rp = std::move(t);
    updateToken();
    if (lp.type != TType::LSquare || rp.type != TType::RSquare)
        assert(false);

    std::cerr << "End " << __FUNCTION__ << ": " << std::string(t) << std::endl;
    return new IndexAccessNode(obj, expr, std::move(lp), std::move(rp));
}

FuncCallNode* CanInitParser::parseFuncCall()
{
    std::cerr << "Begin " << __FUNCTION__ << ": " << std::string(t)
              << std::endl;
    auto id = std::move(t);
    updateToken();
    auto lp = std::move(t);
    updateToken();
    std::vector<ExpressionNode*> params;
    std::vector<Token> comma;

    while (true) {
        params.emplace_back(parseExpression());
        if (t.type == TType::RParen)
            break;
        if (t.type != TType::Comma) {
            assert(false);
        }
        comma.emplace_back(std::move(t));
        updateToken();
    }

    auto rp = std::move(t);
    updateToken();

    std::cerr << "End " << __FUNCTION__ << ": " << std::string(t) << std::endl;
    return new FuncCallNode(
            std::move(id),
            std::move(lp),
            std::move(rp),
            std::move(params),
            std::move(comma));
}

BinExprNode* CanInitParser::parseBinExpr()
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

    auto lval = lastExpr;
    auto delim = std::move(t);
    if (delim.type == TType::Equal && lexer->peek().type == TType::Equal) {
        delim.data = std::string_view(delim.data.data(), 2);
        updateToken();
    }
    updateToken();
    auto rval = parseExpression();

    return new BinExprNode({lval, rval}, std::move(delim));
}
