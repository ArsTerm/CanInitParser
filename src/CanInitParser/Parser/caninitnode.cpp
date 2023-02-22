#include "caninitnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/caninitastnode.h"

ciparser::AstNode* ciparser::CanInitNode::accept(CanInitVisitor* v)
{
    return v->visitCanInit(this);
}

std::string ciparser::CanInitNode::toJson(int spaces)
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
