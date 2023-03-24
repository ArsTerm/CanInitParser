#include "definitionastnode.h"

namespace ciparser {

DefinitionAstNode::DefinitionAstNode(CommentAstNode* comment)
    : m_comment(comment)
{
}

const std::string& DefinitionAstNode::attribute(const std::string& name) const
{
    return m_comment->attributes().at(name);
}

const std::string& DefinitionAstNode::comment() const
{
    return m_comment->comment();
}

}
