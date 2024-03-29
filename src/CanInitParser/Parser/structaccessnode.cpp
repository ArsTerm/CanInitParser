#include "structaccessnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/structaccessastnode.h"

namespace ciparser {

StructAccessNode::~StructAccessNode()
{
    delete m_expr;
    delete m_id;
}

AstNode* StructAccessNode::accept(CanInitVisitor* v)
{
    return v->visitStructAccess(this);
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

}
