#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include "parsenode.h"
#include <caninitlexer.h>

namespace ciparser {

class StructAccessNode;
class IdNode;
class NumberNode;
class IndexAccessNode;
class FuncCallNode;
class BinExprNode;

class ExpressionNode : public ParseNode {
public:
    ExpressionNode() = delete;
    ExpressionNode(ExpressionNode const&) = delete;
    ExpressionNode& operator=(ExpressionNode const&) = delete;

    ExpressionNode(StructAccessNode* n) : m_structAccess(n)
    {
    }

    ExpressionNode(IdNode* n) : m_id(n)
    {
    }

    ExpressionNode(NumberNode* n) : m_number(n)
    {
    }

    ExpressionNode(IndexAccessNode* n) : m_indexAccess(n)
    {
    }

    ExpressionNode(FuncCallNode* n) : m_funcCall(n)
    {
    }

    ExpressionNode(BinExprNode* n) : m_binExpr(n)
    {
    }

    ExpressionNode(ExpressionNode* n) : m_expr(n)
    {
    }

    StructAccessNode const* structAccess() const
    {
        return m_structAccess;
    }

    IdNode const* id() const
    {
        return m_id;
    }

    NumberNode const* number() const
    {
        return m_number;
    }

    IndexAccessNode const* indexAccess() const
    {
        return m_indexAccess;
    }

    FuncCallNode const* funcCall() const
    {
        return m_funcCall;
    }

    BinExprNode const* binExpr() const
    {
        return m_binExpr;
    }

    ExpressionNode const* expr() const
    {
        return m_expr;
    }

private:
    StructAccessNode* m_structAccess = nullptr;
    IdNode* m_id = nullptr;
    NumberNode* m_number = nullptr;
    IndexAccessNode* m_indexAccess = nullptr;
    FuncCallNode* m_funcCall = nullptr;
    BinExprNode* m_binExpr = nullptr;
    ExpressionNode* m_expr = nullptr;

    // ParseNode interface
public:
    AbstractASTNode *accept(CanInitVisitor *) override;
};

}

#endif // EXPRESSIONNODE_H
