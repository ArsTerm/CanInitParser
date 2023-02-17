#ifndef FUNCDEFNODE_H
#define FUNCDEFNODE_H

#include "../CanInitParser_global.h"
#include "parsenode.h"
#include <vector>

namespace ciparser {
class FuncDefNode : public ParseNode {
    DISABLE_COPY(FuncDefNode)
public:
    FuncDefNode(Token const& id, std::vector<std::string> const& params)
        : m_id(id.data), m_params(params)
    {
    }

    FuncDefNode(Token const& id, std::vector<std::string>&& params)
        : m_id(id.data), m_params(std::move(params))
    {
    }

    const std::vector<std::string>& params() const
    {
        return m_params;
    }

    const std::string& id() const
    {
        return m_id;
    }

private:
    std::string m_id;
    std::vector<std::string> m_params;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // FUNCDEFNODE_H
