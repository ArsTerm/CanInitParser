#include "funcdefnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/funcdefastnode.h"

using namespace ciparser;

AstNode* ciparser::FuncDefNode::accept(CanInitVisitor* visitor)
{
    return visitor->visitFuncDef(this);
}

std::string FuncDefNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "Function {\n";
    spaces++;
    fillString(result, spaces, "    ");
    result += "Id: " + m_id + '\n';
    fillString(result, spaces, "    ");
    result += "Params: [\n";
    for (auto& param : m_params) {
        fillString(result, spaces + 1, "    ");
        result += param;
        result += ",\n";
    }
    fillString(result, spaces, "    ");
    result += "]\n";
    fillString(result, spaces - 1, "    ");
    result += "}";
    return result;
}
