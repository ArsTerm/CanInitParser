#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "parsenode.h"

namespace ciparser {
class NumberNode : public ParseNode {
public:
    NumberNode() = delete;
    NumberNode(NumberNode const&) = delete;
    NumberNode& operator=(NumberNode const&) = delete;

    NumberNode(Token const& n) : m_number(n)
    {
    }

    NumberNode(Token&& n) : m_number(std::move(n))
    {
    }

    Token const& number() const
    {
        return m_number;
    }

private:
    Token m_number;

    // ParseNode interface
public:
    AbstractASTNode *accept(CanInitVisitor *) override;
};
}

#endif // NUMBERNODE_H
