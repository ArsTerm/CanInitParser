#ifndef CANINITASTNODE_H
#define CANINITASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"
#include <vector>

namespace ciparser {
class DefinitionASTNode;

class CanInitASTNode : public AbstractASTNode {
    DISABLE_COPY(CanInitASTNode)
public:
    CanInitASTNode(std::vector<DefinitionASTNode*> const& defs)
        : m_defines(defs)
    {
    }

    CanInitASTNode(std::vector<DefinitionASTNode*>&& defs) : m_defines(defs)
    {
    }

    std::vector<DefinitionASTNode*> const& defines() const
    {
        return m_defines;
    }

private:
    std::vector<DefinitionASTNode*> m_defines;
};
}
#endif // CANINITASTNODE_H
