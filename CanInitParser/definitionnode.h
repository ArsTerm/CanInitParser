#ifndef DEFINITIONNODE_H
#define DEFINITIONNODE_H

#include "parsenode.h"
#include <caninitlexer.h>

namespace ciparser {
class ExpressionNode;
class FuncCallNode;
class DefinitionNode : public ParseNode {
public:
    DefinitionNode() = delete;
    DefinitionNode(DefinitionNode const&) = delete;
    DefinitionNode& operator=(DefinitionNode const&) = delete;

    DefinitionNode(
            Token const& define,
            Token const& id,
            ExpressionNode* expr = nullptr)
        : m_define(define), m_id(id), m_expr(expr)
    {
    }

    DefinitionNode(Token&& define, Token&& id, ExpressionNode* expr = nullptr)
        : m_define(std::move(define)), m_id(std::move(id)), m_expr(expr)
    {
    }

    DefinitionNode(
            Token const& define,
            FuncCallNode* defNode,
            ExpressionNode* expr = nullptr)
        : m_define(define), m_funcDef(defNode), m_expr(expr)
    {
    }

    DefinitionNode(
            Token&& define,
            FuncCallNode* defNode,
            ExpressionNode* expr = nullptr)
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

    ExpressionNode const* expr() const
    {
        return m_expr;
    }

    FuncCallNode const* funcDef() const
    {
        return m_funcDef;
    }

private:
    Token m_define;
    Token m_id;
    FuncCallNode* m_funcDef = nullptr;
    ExpressionNode* m_expr;

    // ParseNode interface
public:
    AbstractASTNode *accept(CanInitVisitor *) override;
};
}

#endif // DEFINITIONNODE_H
