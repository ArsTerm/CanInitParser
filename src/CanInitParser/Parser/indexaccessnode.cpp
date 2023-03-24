#include "indexaccessnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/indexaccessastnode.h"

namespace ciparser {

IndexAccessNode::~IndexAccessNode()
{
    delete m_expression;
    delete m_index;
}

AstNode* IndexAccessNode::accept(CanInitVisitor* v)
{
    return v->visitIndexAccess(this);
}

std::string IndexAccessNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "Index {\n";
    spaces++;
    fillString(result, spaces, "    ");
    result += "value: \n";
    result += m_expression->toJson(spaces + 1);
    result += '\n';
    fillString(result, spaces, "    ");
    result += "index: \n";
    result += m_index->toJson(spaces + 1);
    result += '\n';
    fillString(result, spaces - 1, "    ");
    result += '}';

    return result;
}

}
