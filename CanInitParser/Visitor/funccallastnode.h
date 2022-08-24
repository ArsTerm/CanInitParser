#ifndef FUNCCALLASTNODE_H
#define FUNCCALLASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"
#include <string>
#include <vector>

namespace ciparser {
class FuncCallASTNode : public AbstractASTNode {
    DISABLE_COPY(FuncCallASTNode);

public:
    FuncCallASTNode(
            std::string const& name,
            std::vector<AbstractASTNode*> const& params)
        : m_name(name), m_params(params)
    {
    }

    FuncCallASTNode(std::string&& name, std::vector<AbstractASTNode*>&& params)
        : m_name(std::move(name)), m_params(std::move(params))
    {
    }

    const std::string& name() const;
    const std::vector<AbstractASTNode*>& params() const;

private:
    std::string m_name;
    std::vector<AbstractASTNode*> m_params;
};
}

#endif // FUNCCALLASTNODE_H
