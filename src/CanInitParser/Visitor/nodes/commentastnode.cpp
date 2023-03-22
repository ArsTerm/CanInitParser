#include "commentastnode.h"
#include "../../Parser/commentnode.h"

namespace ciparser {

CommentAstNode::CommentAstNode(CommentNode* n)
    : m_attributes(std::move(n->m_attributes)),
      m_comment(std::move(n->m_comment))
{
}

const std::string* CommentAstNode::attribute(const std::string& name) const
{
    auto it = m_attributes.find(name);
    if (it == m_attributes.end())
        return nullptr;

    return &it->second;
}

}
