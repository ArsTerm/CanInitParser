#ifndef STRUCTACCESSNODE_H
#define STRUCTACCESSNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;
class StructAccessNode : public ParseNode {
public:
    StructAccessNode() = delete;
    StructAccessNode(StructAccessNode const&) = delete;
    StructAccessNode& operator=(StructAccessNode const&) = delete;

    StructAccessNode(ParseNode* id, ParseNode* expr) : m_expr(expr), m_id(id)
    {
    }

    ParseNode* id() const
    {
        return m_id;
    }

    ParseNode* expr() const
    {
        return m_expr;
    }

private:
    ParseNode* m_expr;
    ParseNode* m_id;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // STRUCTACCESSNODE_H
