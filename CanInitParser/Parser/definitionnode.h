#ifndef DEFINITIONNODE_H
#define DEFINITIONNODE_H

#include "parsenode.h"
#include <caninitlexer.h>

namespace ciparser {
class FuncDefNode;
class DefinitionNode : public ParseNode {
public:
    DefinitionNode() = delete;
    DefinitionNode(DefinitionNode const&) = delete;
    DefinitionNode& operator=(DefinitionNode const&) = delete;

    DefinitionNode(Token const& id, ParseNode* expr = nullptr)
        : m_id(id.data), m_expr(expr)
    {
    }

    DefinitionNode(FuncDefNode* defNode, ParseNode* expr = nullptr)
        : m_funcDef(defNode), m_expr(expr)
    {
    }

    std::string const& id() const
    {
        return m_id;
    }

    ParseNode* expr() const
    {
        return m_expr;
    }

    FuncDefNode const* funcDef() const
    {
        return m_funcDef;
    }

private:
    std::string m_id;
    FuncDefNode* m_funcDef = nullptr;
    ParseNode* m_expr;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // DEFINITIONNODE_H
