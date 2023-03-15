#ifndef DEFINITIONNODE_H
#define DEFINITIONNODE_H

#include "../caninitlexer.h"
#include "parsenode.h"

namespace ciparser {
class FuncDefNode;
class CommentNode;

class DefinitionNode : public ParseNode {
public:
    DefinitionNode() = delete;
    DefinitionNode(DefinitionNode const&) = delete;
    DefinitionNode& operator=(DefinitionNode const&) = delete;

    DefinitionNode(
            Token const& id,
            ParseNode* expr = nullptr,
            CommentNode* comment = nullptr)
        : m_id(id.data), m_expr(expr), m_comment(comment)
    {
    }

    DefinitionNode(
            FuncDefNode* defNode,
            ParseNode* expr = nullptr,
            CommentNode* comment = nullptr)
        : m_funcDef(defNode), m_expr(expr), m_comment(comment)
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

    FuncDefNode* funcDef() const
    {
        return m_funcDef;
    }

    CommentNode* comment() const
    {
        return m_comment;
    }

private:
    std::string m_id;
    FuncDefNode* m_funcDef = nullptr;
    ParseNode* m_expr;
    CommentNode* m_comment;

    // ParseNode interface
public:
    AstNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // DEFINITIONNODE_H
