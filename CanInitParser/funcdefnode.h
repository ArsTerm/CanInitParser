#ifndef FUNCDEFNODE_H
#define FUNCDEFNODE_H

#include "CanInitParser_global.h"
#include "parsenode.h"
#include <vector>

namespace ciparser {
class FuncDefNode : public ParseNode {
    DISABLE_COPY(FuncDefNode)
public:
    FuncDefNode(
            Token const& id,
            std::vector<Token> const& params,
            std::vector<Token> const& dots,
            Token const& lp,
            Token const& rp)
        : m_id(id), m_params(params), m_dots(dots), m_lp(lp), m_rp(rp)
    {
    }

    FuncDefNode(
            Token&& id,
            std::vector<Token>&& params,
            std::vector<Token>&& dots,
            Token&& lp,
            Token&& rp)
        : m_id(std::move(id)),
          m_params(std::move(params)),
          m_dots(std::move(dots)),
          m_lp(std::move(lp)),
          m_rp(std::move(rp))
    {
    }

    const std::vector<Token>& params() const
    {
        return m_params;
    }

    const Token& id() const
    {
        return m_id;
    }

    const std::vector<Token>& dots() const
    {
        return m_dots;
    }

    Token const& lp() const
    {
        return m_lp;
    }

    Token const& rp() const
    {
        return m_rp;
    }

private:
    Token m_id;
    std::vector<Token> m_params;
    std::vector<Token> m_dots;
    Token m_lp;
    Token m_rp;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // FUNCDEFNODE_H
