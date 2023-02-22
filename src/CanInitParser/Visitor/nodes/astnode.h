#pragma once

#include <vector>

namespace ciparser {
class AstNode {
public:
    std::vector<AstNode*> const& children() const
    {
        return m_children;
    }

    void appendChild(AstNode* n)
    {
        m_children.emplace_back(n);
    }

    virtual ~AstNode();

private:
    std::vector<AstNode*> m_children;
};
}
