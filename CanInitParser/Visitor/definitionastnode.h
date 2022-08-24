#ifndef DEFINITIONASTNODE_H
#define DEFINITIONASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"

namespace ciparser {
class DefinitionASTNode : public AbstractASTNode {
    DISABLE_COPY(DefinitionASTNode)
public:
    DefinitionASTNode(AbstractASTNode* type, AbstractASTNode* value)
        : m_type(type), m_value(value)
    {
    }

    AbstractASTNode* type() const
    {
        return m_type;
    }

    AbstractASTNode* value() const
    {
        return m_value;
    }

private:
    AbstractASTNode* m_type;
    AbstractASTNode* m_value;
};
}
#endif // DEFINITIONASTNODE_H
