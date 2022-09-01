#include "definitionnode.h"
#include "Visitor/caninitvisitor.h"
#include "Visitor/definitionastnode.h"

using ciparser::DefinitionNode;

ciparser::AbstractASTNode* ciparser::DefinitionNode::accept(CanInitVisitor* v)
{
    return v->visitDefinition(this);
}
