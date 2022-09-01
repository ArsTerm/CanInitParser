#include "binexprnode.h"
#include "Visitor/binexprastnode.h"
#include "Visitor/caninitvisitor.h"

ciparser::AbstractASTNode* ciparser::BinExprNode::accept(CanInitVisitor* v)
{
    return v->visitBinExpr(this);
}
