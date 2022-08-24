#ifndef FUNCCALLNODE_H
#define FUNCCALLNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;

class FuncCallNode : public ParseNode {
public:
    FuncCallNode() = delete;
    FuncCallNode(FuncCallNode const&) = delete;
    FuncCallNode& operator=(FuncCallNode const&) = delete;

    FuncCallNode(
            Token const& id,
            Token const& lp,
            Token const& rp,
            std::vector<ExpressionNode*> const& expr,
            std::vector<Token> const& comma)
        : m_id(id), m_LParen(lp), m_RParen(rp), m_expr(expr), m_comma(comma)
    {
    }

    FuncCallNode(
            Token&& id,
            Token&& lp,
            Token&& rp,
            std::vector<ExpressionNode*>&& expr,
            std::vector<Token>&& comma)
        : m_id(std::move(id)),
          m_LParen(std::move(lp)),
          m_RParen(std::move(rp)),
          m_expr(std::move(expr)),
          m_comma(std::move(comma))
    {
    }

    Token const& id() const
    {
        return m_id;
    }

    Token const& LParen() const
    {
        return m_LParen;
    }

    Token const& RParen() const
    {
        return m_RParen;
    }

    std::vector<ExpressionNode*> const& expr() const
    {
        return m_expr;
    }

    std::vector<Token> const& comma() const
    {
        return m_comma;
    }

private:
    Token m_id;
    Token m_LParen;
    Token m_RParen;
    std::vector<ExpressionNode*> m_expr;
    std::vector<Token> m_comma;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // FUNCCALLNODE_H
