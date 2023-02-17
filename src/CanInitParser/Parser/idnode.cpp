#include "idnode.h"
#include "../Visitor/caninitvisitor.h"
//#include "Visitor/idastnode.h"

using ciparser::IdNode;

ciparser::AbstractASTNode* ciparser::IdNode::accept(CanInitVisitor* v)
{
    return nullptr;// v->visitId(this);
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
