#include "idnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/idastnode.h"

using ciparser::IdNode;

ciparser::AstNode* ciparser::IdNode::accept(CanInitVisitor* v)
{
    return v->visitId(this);
}

std::string IdNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "Id {\n";
    fillString(result, spaces + 1, "    ");
    result += "name: " + m_id + '\n';
    fillString(result, spaces, "    ");
    result += '}';
    return result;
}
