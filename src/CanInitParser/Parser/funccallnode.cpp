#include "funccallnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/funccallastnode.h"

namespace ciparser {

FuncCallNode::~FuncCallNode()
{
    for (auto arg : m_expr)
        delete arg;
}

AstNode* FuncCallNode::accept(CanInitVisitor* v)
{
    return v->visitFuncCall(this);
}

std::string FuncCallNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "FunCall {\n";
    spaces++;
    fillString(result, spaces, "    ");
    result += "Id: " + m_id + '\n';
    fillString(result, spaces, "    ");
    result += "Arguments: [\n";
    for (auto arg : m_expr) {
        result += arg->toJson(spaces + 1);
        result += ",\n";
    }
    fillString(result, spaces, "    ");
    result += "]\n";
    fillString(result, spaces - 1, "    ");
    result += '}';
    return result;
}

}
