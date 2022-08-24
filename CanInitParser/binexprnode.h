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

    BinExprNode(ParseNode* l, ParseNode* r, Token const& delim)
        : m_l(l), m_r(r), m_delim(delim)
    {
    }

    BinExprNode(ParseNode* l, ParseNode* r, Token&& delim)
        : m_l(l), m_r(r), m_delim(std::move(delim))
    {
    }

    ParseNode* l() const
    {
        return m_l;
    }

    ParseNode* r() const
    {
        return m_r;
    }

    Token const& delim() const
    {
        return m_delim;
    }

private:
    ParseNode* m_l;
    ParseNode* m_r;
    Token m_delim;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // BINEXPRNODE_H
