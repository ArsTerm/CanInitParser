#ifndef IDNODE_H
#define IDNODE_H

#include "parsenode.h"

namespace ciparser {
class IdNode : public ParseNode {
public:
    IdNode() = delete;
    IdNode(IdNode const&) = delete;
    IdNode& operator=(IdNode const&) = delete;

    IdNode(Token const& id) : m_id(id)
    {
    }

    IdNode(Token&& id) : m_id(std::move(id))
    {
    }

    Token const& id() const
    {
        return m_id;
    }

private:
    Token m_id;

    // ParseNode interface
public:
    AbstractASTNode *accept(CanInitVisitor *) override;
};
}

#endif // IDNODE_H
