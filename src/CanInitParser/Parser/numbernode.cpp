#include "numbernode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/numberastnode.h"

using ciparser::NumberNode;

ciparser::AstNode* ciparser::NumberNode::accept(CanInitVisitor* v)
{
    return v->visitNumber(this);
}

std::string NumberNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "Number {\n";
    fillString(result, spaces + 1, "    ");
    result += "value: " + m_number + '\n';
    fillString(result, spaces, "    ");
    result += '}';

    return result;
}
