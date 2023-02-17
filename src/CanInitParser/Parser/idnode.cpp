#include "idnode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/idastnode.h"

using ciparser::IdNode;

ciparser::AbstractASTNode* ciparser::IdNode::accept(CanInitVisitor* v)
{
    return v->visitId(this);
}
