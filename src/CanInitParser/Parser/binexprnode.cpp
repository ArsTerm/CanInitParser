#include "binexprnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/binexprastnode.h"
#include "../caninitlexer.h"

ciparser::AstNode* ciparser::BinExprNode::accept(CanInitVisitor* v)
{
    return v->visitBinExpr(this);
}

std::string ciparser::BinExprNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "BinExpr {\n";
    spaces++;
    fillString(result, spaces, "    ");
    result += std::string("operation: ")
            + CanInitLexer::typeToString((TType)m_op) + '\n';
    fillString(result, spaces, "    ");
    result += "left:\n";
    result += m_l->toJson(spaces + 1);
    result += '\n';
    fillString(result, spaces, "    ");
    result += "right:\n";
    result += m_r->toJson(spaces + 1);
    result += '\n';
    fillString(result, spaces - 1, "    ");
    result += '}';

    return result;
}
