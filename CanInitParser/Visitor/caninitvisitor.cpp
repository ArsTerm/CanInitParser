#include "caninitvisitor.h"
#include "Parser/binexprnode.h"
#include "Parser/caninitnode.h"
#include "Parser/definitionnode.h"
#include "Parser/funccallnode.h"
#include "Parser/idnode.h"
#include "Parser/indexaccessnode.h"
#include "Parser/numbernode.h"
#include "Parser/parsenode.h"
#include "Parser/structaccessnode.h"
#include <cassert>

#include <typeinfo>

using namespace ciparser;

CanInitVisitor::CanInitVisitor(ParseNode* root) : root(root)
{
}

void CanInitVisitor::parse()
{
    root->accept(this);
}

void* CanInitVisitor::visitDefinition(const DefinitionNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitBinExpr(const BinExprNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitCanInit(const CanInitNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitFuncCall(const FuncCallNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitId(const IdNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitIndexAccess(const IndexAccessNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitNumber(const NumberNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitStructAccess(const StructAccessNode*)
{
    return nullptr;
}

void* CanInitVisitor::visitFuncDef(const FuncDefNode*)
{
    return nullptr;
}
