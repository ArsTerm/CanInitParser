#ifndef CANINITVISITOR_H
#define CANINITVISITOR_H

#include "CanInitParser_global.h"

namespace ciparser {
class AbstractASTNode;
class DefinitionASTNode;
class BinExprASTNode;
class CanInitASTNode;
class ExpressionASTNode;
class FuncCallASTNode;
class IdASTNode;
class IndexAccessASTNode;
class NumberASTNode;
class StructAccessASTNode;
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
class FuncDefASTNode;

class CANINITPARSER_EXPORT CanInitVisitor {
public:
    CanInitVisitor(ParseNode* root) : root(root)
    {
    }

    AbstractASTNode* parse();

    DefinitionASTNode* visitDefinition(DefinitionNode const*);
    BinExprASTNode* visitBinExpr(BinExprNode const*);
    CanInitASTNode* visitCanInit(CanInitNode const*);
    AbstractASTNode* visitExpression(ExpressionNode const*);
    FuncCallASTNode* visitFuncCall(FuncCallNode const*);
    IdASTNode* visitId(IdNode const*);
    IndexAccessASTNode* visitIndexAccess(IndexAccessNode const*);
    NumberASTNode* visitNumber(NumberNode const*);
    StructAccessASTNode* visitStructAccess(StructAccessNode const*);
    FuncDefASTNode* visitFuncDef(FuncDefNode const*);

private:
    ParseNode* root;
};
}

#endif // CANINITVISITOR_H
