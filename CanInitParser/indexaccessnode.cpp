#include "indexaccessnode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/indexaccessastnode.h"

using ciparser::IndexAccessNode;

ciparser::AbstractASTNode* ciparser::IndexAccessNode::accept(CanInitVisitor* v)
{
    return v->visitIndexAccess(this);
}
