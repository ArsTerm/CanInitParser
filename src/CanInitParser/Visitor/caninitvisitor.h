#ifndef CANINITVISITOR_H
#define CANINITVISITOR_H

#include "CanInitParser_global.h"

namespace ciparser {
class DefinitionNode;
class BinExprNode;
class CanInitNode;
class ExpressionNode;
class FuncCallNode;
class IdNode;
class IndexAccessNode;
class NumberNode;
class ParseNode;
class StructAccessNode;
class FuncDefNode;

class CANINITPARSER_EXPORT CanInitVisitor {
public:
    CanInitVisitor(ParseNode* root);

    void parse();

    void* visitDefinition(DefinitionNode const*);
    void* visitBinExpr(BinExprNode const*);
    void* visitCanInit(CanInitNode const*);
    void* visitFuncCall(FuncCallNode const*);
    void* visitId(IdNode const*);
    void* visitIndexAccess(IndexAccessNode const*);
    void* visitNumber(NumberNode const*);
    void* visitStructAccess(StructAccessNode const*);
    void* visitFuncDef(FuncDefNode const*);

private:
    ParseNode* root;
};
}

#endif // CANINITVISITOR_H
