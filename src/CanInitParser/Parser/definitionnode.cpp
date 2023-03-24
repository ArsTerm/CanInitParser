#include "definitionnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/definitionastnode.h"
#include "commentnode.h"
#include "funcdefnode.h"

using ciparser::DefinitionNode;

ciparser::AstNode* ciparser::DefinitionNode::accept(CanInitVisitor* v)
{
    return v->visitDefinition(this);
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
        result += ",\n";
        if (m_comment) {
            result += m_comment->toJson(spaces + 1);
            result += "\n";
        }
        fillString(result, spaces, "    ");
        result += "}";
    } else {
        result += "DefId {\n";
        fillString(result, spaces + 1, "    ");
        result += "Id: " + m_id + '\n';
        if (m_expr) {
            result += m_expr->toJson(spaces + 1);
            result += ",\n";
        }
        if (m_comment) {
            result += m_comment->toJson(spaces + 1);
            result += "\n";
        }
        fillString(result, spaces, "    ");
        result += "}";
    }
    return result;
}
