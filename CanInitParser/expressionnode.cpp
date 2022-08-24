#include "expressionnode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/expressionastnode.h"

using ciparser::ExpressionNode;

ciparser::AbstractASTNode* ciparser::ExpressionNode::accept(CanInitVisitor* v)
{
    return v->visitExpression(this);
}
