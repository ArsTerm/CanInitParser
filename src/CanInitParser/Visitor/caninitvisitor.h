#pragma once

#include "../CanInitParser_global.h"
#include "types/alias.h"
#include "types/id.h"
#include "types/message.h"
#include "types/value.h"

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
class AstNode;
class CommentNode;
class BinExprAstNode;
class CanInitAstNode;
class DefinitionAstNode;
class FuncCallAstNode;
class FuncDefAstNode;
class IdAstNode;
class NumberAstNode;
class StructAccessAstNode;
class IndexAccessAstNode;
class NumberAstNode;
class CommentAstNode;
class Message;

class CANINITPARSER_EXPORT CanInitVisitor {
public:
    CanInitVisitor();

    AstNode* visit(ParseNode*);

    DefinitionAstNode* visitDefinition(DefinitionNode*);
    BinExprAstNode* visitBinExpr(BinExprNode*);
    CanInitAstNode* visitCanInit(CanInitNode*);
    FuncCallAstNode* visitFuncCall(FuncCallNode*);
    IdAstNode* visitId(IdNode*);
    IndexAccessAstNode* visitIndexAccess(IndexAccessNode*);
    NumberAstNode* visitNumber(NumberNode*);
    StructAccessAstNode* visitStructAccess(StructAccessNode*);
    FuncDefAstNode* visitFuncDef(FuncDefNode*);
    CommentAstNode* visitCommentNode(CommentNode*);

    Id::Set&& move_ids()
    {
        return std::move(ids);
    }

    Id::Set const& get_ids()
    {
        return ids;
    }

private:
    std::vector<Alias> aliases;
    std::vector<Value> values;
    std::vector<Message> messages;
    Id::Set ids;

    Message* parseMessage(StructAccessAstNode*);
    Message* parseMessage(IndexAccessAstNode*);
};
}
