#include "caninitvisitor.h"
#include "../Parser/binexprnode.h"
#include "../Parser/caninitnode.h"
#include "../Parser/definitionnode.h"
#include "../Parser/funccallnode.h"
#include "../Parser/funcdefnode.h"
#include "../Parser/idnode.h"
#include "../Parser/indexaccessnode.h"
#include "../Parser/numbernode.h"
#include "../Parser/parsenode.h"
#include "../Parser/structaccessnode.h"

#include "nodes/astnode.h"
#include "nodes/binexprastnode.h"
#include "nodes/caninitastnode.h"
#include "nodes/definitionastnode.h"
#include "nodes/funccallastnode.h"
#include "nodes/funcdefastnode.h"
#include "nodes/idastnode.h"
#include "nodes/indexaccessastnode.h"
#include "nodes/numberastnode.h"
#include "nodes/structaccessastnode.h"

#include "expr.h"
#include <cassert>
#include <typeinfo>

using namespace ciparser;

CanInitVisitor::CanInitVisitor()
{
}

AstNode* CanInitVisitor::visit(ParseNode* n)
{
    return n->accept(this);
}

DefinitionAstNode* CanInitVisitor::visitDefinition(DefinitionNode* n)
{
    auto id = n->id();

    if (n->funcDef()) {
        auto func = n->funcDef()->accept(this);
    } else {
        auto expr = n->expr()->accept(this);
        if (auto node = dynamic_cast<BinExprAstNode*>(expr)) {
            auto value = new Value(id, node->expr());
            ids.emplace(id, value);
        } else if (auto node = dynamic_cast<IdAstNode*>(expr)) {
            auto alias = new Alias(id, node->getName());
            ids.emplace(id, alias);
        } else if (auto node = dynamic_cast<NumberAstNode*>(expr)) {
            auto value = new Value(id, new NumberExpr(node->value()));
            ids.emplace(id, value);
        } else {
            assert(false);
        }
    }

    return new DefinitionAstNode;
}

BinExprAstNode* CanInitVisitor::visitBinExpr(BinExprNode* n)
{
    Expr *l, *r;
    std::vector<std::string> dependencies;

    auto lNode = n->l()->accept(this);
    if (auto node = dynamic_cast<BinExprAstNode*>(lNode)) {
        l = node->expr();
        dependencies.insert(
                dependencies.end(),
                node->dependencies().begin(),
                node->dependencies().end());
    } else if (auto id = dynamic_cast<IdAstNode*>(lNode)) {
        auto alias = new Alias("", id->name());
        l = new IdExpr(alias);
        dependencies.emplace_back(id->getName());
    } else if (auto num = dynamic_cast<NumberAstNode*>(lNode)) {
        l = new NumberExpr(num->value());
    } else {
        assert(false);
    }

    auto rNode = n->r()->accept(this);
    if (auto node = dynamic_cast<BinExprAstNode*>(rNode)) {
        r = node->expr();
        dependencies.insert(
                dependencies.end(),
                node->dependencies().begin(),
                node->dependencies().end());
    } else if (auto id = dynamic_cast<IdAstNode*>(rNode)) {
        auto alias = new Alias("", id->name());
        r = new IdExpr(alias);
        dependencies.emplace_back(id->getName());
    } else if (auto num = dynamic_cast<NumberAstNode*>(rNode)) {
        r = new NumberExpr(num->value());
    } else {
        assert(false);
    }

    Expr* target;

    switch (n->operation()) {
    case BinExprNode::Sum:
        target = new SumExpr(l, r);
        break;
    case BinExprNode::Sub:
        target = new SubExpr(l, r);
        break;
    case BinExprNode::Mul:
        target = new MulExpr(l, r);
        break;
    case BinExprNode::Div:
        target = new DivExpr(l, r);
        break;
    case BinExprNode::And:
        target = new AndBinExpr(l, r);
        break;
    default:
        assert(false);
    }

    return new BinExprAstNode(target, std::move(dependencies));
}

CanInitAstNode* CanInitVisitor::visitCanInit(CanInitNode* n)
{
    auto node = new CanInitAstNode;
    for (auto child : n->childrens()) {
        node->appendChild(child->accept(this));
    }

    return node;
}

FuncCallAstNode* CanInitVisitor::visitFuncCall(FuncCallNode*)
{
    return nullptr;
}

IdAstNode* CanInitVisitor::visitId(IdNode* n)
{
    return new IdAstNode(n->id());
}

IndexAccessAstNode* CanInitVisitor::visitIndexAccess(IndexAccessNode*)
{
    return nullptr;
}

NumberAstNode* CanInitVisitor::visitNumber(NumberNode* n)
{
    return new NumberAstNode(std::stoi(n->number()));
}

StructAccessAstNode* CanInitVisitor::visitStructAccess(StructAccessNode*)
{
    return nullptr;
}

FuncDefAstNode* CanInitVisitor::visitFuncDef(FuncDefNode*)
{
    return nullptr;
}
