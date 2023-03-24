#include "caninitnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/caninitastnode.h"

namespace ciparser {

CanInitNode::~CanInitNode()
{
    for (auto child : m_childrens)
        delete child;
}

ciparser::AstNode* CanInitNode::accept(CanInitVisitor* v)
{
    return v->visitCanInit(this);
}

std::string CanInitNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "CanInit {\n";
    for (auto child : m_childrens) {
        result += child->toJson(spaces + 1);
        result += ",\n";
    }
    fillString(result, spaces, "    ");
    result += "}";
    return result;
}

}
