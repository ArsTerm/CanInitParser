#include "astnode.h"

namespace ciparser {
AstNode::~AstNode()
{
    for (auto child : m_children) {
        delete child;
    }
}
}
