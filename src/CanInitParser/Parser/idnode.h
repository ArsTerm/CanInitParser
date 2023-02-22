#ifndef IDNODE_H
#define IDNODE_H

#include "parsenode.h"

namespace ciparser {
class IdNode : public ParseNode {
public:
    IdNode() = delete;
    IdNode(IdNode const&) = delete;
    IdNode& operator=(IdNode const&) = delete;

    IdNode(Token const& id) : m_id(id.data)
    {
    }

    std::string const& id() const
    {
        return m_id;
    }

private:
    std::string m_id;

    // ParseNode interface
public:
    AstNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // IDNODE_H
