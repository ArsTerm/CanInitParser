#include "funcdefnode.h"

using namespace ciparser;

AbstractASTNode* ciparser::FuncDefNode::accept(CanInitVisitor*)
{
    return nullptr;
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
