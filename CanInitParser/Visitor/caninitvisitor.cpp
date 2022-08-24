#include "caninitvisitor.h"
#include "binexprastnode.h"
#include "binexprnode.h"
#include "caninitastnode.h"
#include "caninitnode.h"
#include "definitionastnode.h"
#include "definitionnode.h"
#include "expressionastnode.h"
#include "expressionnode.h"
#include "funccallastnode.h"
#include "funccallnode.h"
#include "idastnode.h"
#include "idnode.h"
#include "indexaccessastnode.h"
#include "indexaccessnode.h"
#include "numberastnode.h"
#include "numbernode.h"
#include "parsenode.h"
#include "structaccessastnode.h"
#include "structaccessnode.h"
#include <cassert>

#include <typeinfo>

using namespace ciparser;

AbstractASTNode* CanInitVisitor::parse()
{
    return root->accept(this);
}

DefinitionASTNode* CanInitVisitor::visitDefinition(DefinitionNode const* n)
{
    AbstractASTNode* type = nullptr;
    if (n->funcDef()) {
        type = visitFuncCall(n->funcDef());
    } else if (n->id().type == CanInitLexer::Id) {
        IdNode tmp(n->id());
        type = visitId(&tmp);
    } else
        assert(false);

    return new DefinitionASTNode(type, visitExpression(n->expr()));
}

BinExprASTNode* CanInitVisitor::visitBinExpr(BinExprNode const* n)
{
    using TType = CanInitLexer::TokenType;
    using Op = BinExprASTNode::Operation;
    auto lval = visitExpression(n->expr()[0]);
    auto rval = visitExpression(n->expr()[1]);
    Op op;
    switch (n->delim().type) {
    case TType::And:
        op = Op::And;
        break;
    case TType::Or:
        op = Op::Or;
        break;
    case TType::Plus:
        op = Op::Sum;
        break;
    case TType::Minus:
        op = Op::Sub;
        break;
    case TType::Equal:
        op = n->delim().data.size() == 2 ? Op::Comparsion : Op::Assign;
        break;
    default:
        assert(false);
        _STL_UNREACHABLE;
    }

    return new BinExprASTNode(lval, rval, op);
}

#include <iostream>

CanInitASTNode* CanInitVisitor::visitCanInit(CanInitNode const* n)
{
    std::vector<DefinitionASTNode*> defs;
    std::cerr << "Defs size: " << n->childrens().size() << '\n';
    for (auto const& d : n->childrens()) {
        std::cerr << "Node type: " << typeid(*d).name() << '\n';
        if (typeid(*d) != typeid(DefinitionNode))
            assert(false);
        defs.emplace_back(visitDefinition(static_cast<DefinitionNode*>(d)));
    }

    return new CanInitASTNode(std::move(defs));
}

AbstractASTNode* CanInitVisitor::visitExpression(ExpressionNode const* n)
{
    if (n->binExpr())
        return visitBinExpr(n->binExpr());
    if (n->expr())
        return visitExpression(n->expr());
    if (n->funcCall())
        return visitFuncCall(n->funcCall());
    if (n->id())
        return visitId(n->id());
    if (n->indexAccess())
        return visitIndexAccess(n->indexAccess());
    if (n->number())
        return visitNumber(n->number());
    if (n->structAccess())
        return visitStructAccess(n->structAccess());

    assert(false);
    _STL_UNREACHABLE;
}

FuncCallASTNode* CanInitVisitor::visitFuncCall(FuncCallNode const* n)
{
    IdNode tmpn(n->id());
    auto name = std::move(visitId(&tmpn)->name());
    std::vector<AbstractASTNode*> params;
    for (auto const& d : n->expr())
        params.emplace_back(d->accept(this));

    return new FuncCallASTNode(std::move(name), std::move(params));
}

IdASTNode* CanInitVisitor::visitId(IdNode const* n)
{
    return new IdASTNode(std::string(n->id().data));
}

IndexAccessASTNode* CanInitVisitor::visitIndexAccess(IndexAccessNode const* n)
{
    return new IndexAccessASTNode(
            visitExpression(n->expression()), visitExpression(n->index()));
}

NumberASTNode* CanInitVisitor::visitNumber(NumberNode const* n)
{
    return new NumberASTNode(std::string(n->number().data));
}

StructAccessASTNode*
CanInitVisitor::visitStructAccess(StructAccessNode const* n)
{
    return new StructAccessASTNode(
            visitExpression(n->expr()), std::string(n->id().data));
}
