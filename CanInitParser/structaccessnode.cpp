#include "structaccessnode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/structaccessastnode.h"

using ciparser::StructAccessNode;

ciparser::AbstractASTNode* ciparser::StructAccessNode::accept(CanInitVisitor* v)
{
    return v->visitStructAccess(this);
}
