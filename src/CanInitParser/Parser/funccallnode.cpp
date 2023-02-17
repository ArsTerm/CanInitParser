#include "funccallnode.h"
#include "../Visitor/caninitvisitor.h"
//#include "Visitor/funccallastnode.h"

ciparser::AbstractASTNode* ciparser::FuncCallNode::accept(CanInitVisitor* v)
{
    return nullptr;// v->visitFuncCall(this);
}

std::string ciparser::FuncCallNode::toJson(int spaces)
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
