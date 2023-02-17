#ifndef FUNCCALLNODE_H
#define FUNCCALLNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;

class FuncCallNode : public ParseNode {
public:
    FuncCallNode() = delete;
    FuncCallNode(FuncCallNode const&) = delete;
    FuncCallNode& operator=(FuncCallNode const&) = delete;

    FuncCallNode(Token const& id, std::vector<ParseNode*> const& expr)
        : m_id(id.data), m_expr(expr)
    {
    }

    std::string const& id() const
    {
        return m_id;
    }

    std::vector<ParseNode*> const& expr() const
    {
        return m_expr;
    }

private:
    std::string m_id;
    std::vector<ParseNode*> m_expr;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // FUNCCALLNODE_H
