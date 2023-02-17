#include "numbernode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/numberastnode.h"

using ciparser::NumberNode;

ciparser::AbstractASTNode* ciparser::NumberNode::accept(CanInitVisitor* v)
{
    return v->visitNumber(this);
}
