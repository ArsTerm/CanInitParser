#ifndef STRUCTACCESSASTNODE_H
#define STRUCTACCESSASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"
#include <string>

namespace ciparser {
class StructAccessASTNode : public AbstractASTNode {
    DISABLE_COPY(StructAccessASTNode);

public:
    StructAccessASTNode(AbstractASTNode* obj, std::string const& field)
        : m_object(obj), m_field(field)
    {
    }

    StructAccessASTNode(AbstractASTNode* obj, std::string&& field)
        : m_object(obj), m_field(std::move(field))
    {
    }

    AbstractASTNode const* object() const
    {
        return m_object;
    }

    std::string const& field() const
    {
        return m_field;
    }

private:
    AbstractASTNode* m_object;
    std::string m_field;
};
}

#endif // STRUCTACCESSASTNODE_H
