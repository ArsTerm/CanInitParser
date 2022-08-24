#ifndef INDEXACCESSNODE_H
#define INDEXACCESSNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;
class IndexAccessNode : public ParseNode {
public:
    IndexAccessNode(
            ExpressionNode* expr,
            ExpressionNode* idx,
            Token const& ls,
            Token const& rs)
        : m_expression(expr), m_index(idx), m_LSquare(ls), m_RSquare(rs)
    {
    }

    IndexAccessNode(
            ExpressionNode* expr, ExpressionNode* idx, Token&& ls, Token&& rs)
        : m_expression(expr),
          m_index(idx),
          m_LSquare(std::move(ls)),
          m_RSquare(std::move(rs))
    {
    }

    IndexAccessNode() = delete;
    IndexAccessNode(IndexAccessNode const&) = delete;
    IndexAccessNode& operator=(IndexAccessNode const&) = delete;

    ExpressionNode const* expression() const
    {
        return m_expression;
    }

    ExpressionNode const* index() const
    {
        return m_index;
    }

    Token const& LSquare() const
    {
        return m_LSquare;
    }

    Token const& RSquare() const
    {
        return m_RSquare;
    }

private:
    ExpressionNode* m_expression = nullptr;
    ExpressionNode* m_index = nullptr;
    Token m_LSquare;
    Token m_RSquare;

    // ParseNode interface
public:
    AbstractASTNode *accept(CanInitVisitor *) override;
};
}

#endif // INDEXACCESSNODE_H
