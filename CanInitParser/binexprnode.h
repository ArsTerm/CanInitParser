#ifndef BINEXPRNODE_H
#define BINEXPRNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;
class BinExprNode : public ParseNode {
public:
    BinExprNode() = delete;
    BinExprNode(BinExprNode const&) = delete;
    BinExprNode& operator=(BinExprNode const&) = delete;

    BinExprNode(std::vector<ExpressionNode*> const& expr, Token const& delim)
        : m_expr(expr), m_delim(delim)
    {
    }

    BinExprNode(std::vector<ExpressionNode*>&& expr, Token&& delim)
        : m_expr(std::move(expr)), m_delim(std::move(delim))
    {
    }

    std::vector<ExpressionNode*> const& expr() const
    {
        return m_expr;
    }

    Token const& delim() const
    {
        return m_delim;
    }

private:
    std::vector<ExpressionNode*> m_expr;
    Token m_delim;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // BINEXPRNODE_H
