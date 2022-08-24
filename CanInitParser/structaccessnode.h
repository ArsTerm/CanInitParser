#ifndef STRUCTACCESSNODE_H
#define STRUCTACCESSNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;
class StructAccessNode : public ParseNode {
public:
    StructAccessNode() = delete;
    StructAccessNode(StructAccessNode const&) = delete;
    StructAccessNode& operator=(StructAccessNode const&) = delete;

    StructAccessNode(ExpressionNode* expr, Token const& id, Token const& dot)
        : m_expr(expr), m_id(id), m_dot(dot)
    {
    }

    StructAccessNode(ExpressionNode* expr, Token&& id, Token&& dot)
        : m_expr(expr), m_id(std::move(id)), m_dot(std::move(dot))
    {
    }

    Token const& id() const
    {
        return m_id;
    }

    Token const& dot() const
    {
        return m_dot;
    }

    ExpressionNode const* expr() const
    {
        return m_expr;
    }

private:
    ExpressionNode* m_expr;
    Token m_id;
    Token m_dot;

    // ParseNode interface
public:
    AbstractASTNode *accept(CanInitVisitor *) override;
};
}

#endif // STRUCTACCESSNODE_H
