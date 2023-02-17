#include "caninitnode.h"
//#include "Visitor/caninitastnode.h"
#include "../Visitor/caninitvisitor.h"

ciparser::AbstractASTNode* ciparser::CanInitNode::accept(CanInitVisitor* v)
{
    return nullptr;//v->visitCanInit(this);
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
