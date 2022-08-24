#include "funcdefnode.h"

using namespace ciparser;

AbstractASTNode* ciparser::FuncDefNode::accept(CanInitVisitor*)
{
    return nullptr;
}
