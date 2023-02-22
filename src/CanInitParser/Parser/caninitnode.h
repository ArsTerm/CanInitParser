#ifndef CANINITNODE_H
#define CANINITNODE_H

#include "parsenode.h"

namespace ciparser {
class CanInitNode : public ParseNode {
public:
    CanInitNode() = default;

    void appendChildren(ParseNode* n)
    {
        m_childrens.emplace_back(n);
    }

    std::vector<ParseNode*> const& childrens() const
    {
        return m_childrens;
    }

private:
    std::vector<ParseNode*> m_childrens;

    // ParseNode interface
public:
    AstNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // CANINITNODE_H
