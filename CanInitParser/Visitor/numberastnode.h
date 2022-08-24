#ifndef NUMBERASTNODE_H
#define NUMBERASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"
#include <string>

namespace ciparser {
class NumberASTNode : public AbstractASTNode {
    DISABLE_COPY(NumberASTNode)
public:
    NumberASTNode(std::string const& name) : m_name(name)
    {
    }

    NumberASTNode(std::string&& name) : m_name(name)
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

#endif // NUMBERASTNODE_H
