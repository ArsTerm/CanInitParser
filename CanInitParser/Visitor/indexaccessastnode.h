#ifndef INDEXACCESSASTNODE_H
#define INDEXACCESSASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"

namespace ciparser {
class IndexAccessASTNode : public AbstractASTNode {
    DISABLE_COPY(IndexAccessASTNode)
public:
    IndexAccessASTNode(AbstractASTNode* obj, AbstractASTNode* idx)
        : m_object(obj), m_index(idx)
    {
    }

    AbstractASTNode const* object() const
    {
        return m_object;
    }

    AbstractASTNode const* index() const
    {
        return m_index;
    }

private:
    AbstractASTNode* m_object;
    AbstractASTNode* m_index;
};
}
#endif // INDEXACCESSASTNODE_H
