#ifndef IDASTNODE_H
#define IDASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"
#include <string>

namespace ciparser {
class IdASTNode : public AbstractASTNode {
    DISABLE_COPY(IdASTNode);

public:
    IdASTNode(std::string const& name) : m_name(name)
    {
    }

    IdASTNode(std::string&& name) : m_name(std::move(name))
    {
    }

    std::string const& name() const
    {
        return m_name;
    }

private:
    std::string m_name;
};
}
#endif // IDASTNODE_H
