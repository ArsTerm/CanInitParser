#include "caninitnode.h"
#include "Visitor/caninitastnode.h"
#include "Visitor/caninitvisitor.h"

ciparser::AbstractASTNode* ciparser::CanInitNode::accept(CanInitVisitor* v)
{
    return v->visitCanInit(this);
}
