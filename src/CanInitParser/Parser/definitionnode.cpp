#include "definitionnode.h"
#include "../Visitor/caninitvisitor.h"
//#include "Visitor/definitionastnode.h"
#include "funcdefnode.h"

using ciparser::DefinitionNode;

ciparser::AbstractASTNode* ciparser::DefinitionNode::accept(CanInitVisitor* v)
{
    return nullptr;// v->visitDefinition(this);
}

std::string DefinitionNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    if (m_funcDef) {
        result += "DefFunction {\n";
        result += m_funcDef->toJson(spaces + 1);
        result += ",\n";
        result += m_expr->toJson(spaces + 1);
        result += '\n';
        fillString(result, spaces, "    ");
        result += "}";
    } else {
        result += "DefId {\n";
        fillString(result, spaces + 1, "    ");
        result += "Id: " + m_id + '\n';
        if (m_expr) {
            result += m_expr->toJson(spaces + 1);
            result += '\n';
        }
        fillString(result, spaces, "    ");
        result += "}";
    }
    return result;
}
