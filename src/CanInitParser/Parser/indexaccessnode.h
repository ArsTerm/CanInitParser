#ifndef INDEXACCESSNODE_H
#define INDEXACCESSNODE_H

#include "parsenode.h"

namespace ciparser {
class IndexAccessNode : public ParseNode {
public:
    IndexAccessNode(ParseNode* expr, ParseNode* idx)
        : m_expression(expr), m_index(idx)
    {
    }

    IndexAccessNode() = delete;
    IndexAccessNode(IndexAccessNode const&) = delete;
    IndexAccessNode& operator=(IndexAccessNode const&) = delete;

    ParseNode* expression() const
    {
        return m_expression;
    }

    ParseNode* index() const
    {
        return m_index;
    }

    ~IndexAccessNode() override;

private:
    ParseNode* m_expression = nullptr;
    ParseNode* m_index = nullptr;

    // ParseNode interface
public:
    AstNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // INDEXACCESSNODE_H
