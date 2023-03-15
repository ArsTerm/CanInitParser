#include "commentastnode.h"
#include "../../Parser/commentnode.h"

namespace ciparser {

CommentAstNode::CommentAstNode(CommentNode* n)
    : m_attributes(std::move(n->m_attributes)),
      m_comment(std::move(n->m_comment))
{
}

}
