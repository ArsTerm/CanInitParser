#include "funccallnode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/funccallastnode.h"

ciparser::AbstractASTNode* ciparser::FuncCallNode::accept(CanInitVisitor* v)
{
    return v->visitFuncCall(this);
}
