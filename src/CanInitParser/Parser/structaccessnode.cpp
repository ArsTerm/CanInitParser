#include "structaccessnode.h"
#include "../Visitor/caninitvisitor.h"
//#include "Visitor/structaccessastnode.h"

using ciparser::StructAccessNode;

ciparser::AbstractASTNode* ciparser::StructAccessNode::accept(CanInitVisitor* v)
{
    return nullptr;//v->visitStructAccess(this);
}

std::string StructAccessNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "StructAccess {\n";
    spaces++;
    fillString(result, spaces, "    ");
    result += "object:\n";
    result += m_expr->toJson(spaces + 1);
    result += '\n';
    fillString(result, spaces, "    ");
    result += "field:\n";
    result += m_id->toJson(spaces + 1);
    result += '\n';
    fillString(result, spaces - 1, "    ");
    result += '}';

    return result;
}
