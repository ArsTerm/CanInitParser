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

    DefinitionNode(
            Token const& define, Token const& id, ParseNode* expr = nullptr)
        : m_define(define), m_id(id), m_expr(expr)
    {
    }

    DefinitionNode(Token&& define, Token&& id, ParseNode* expr = nullptr)
        : m_define(std::move(define)), m_id(std::move(id)), m_expr(expr)
    {
    }

    DefinitionNode(
            Token const& define,
            FuncDefNode* defNode,
            ParseNode* expr = nullptr)
        : m_define(define), m_funcDef(defNode), m_expr(expr)
    {
    }

    DefinitionNode(
            Token&& define, FuncDefNode* defNode, ParseNode* expr = nullptr)
        : m_define(std::move(define)), m_funcDef(defNode), m_expr(expr)
    {
    }

    Token const& define() const
    {
        return m_define;
    }

    Token const& id() const
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
    Token m_define;
    Token m_id;
    FuncDefNode* m_funcDef = nullptr;
    ParseNode* m_expr;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
};
}

#endif // DEFINITIONNODE_H
