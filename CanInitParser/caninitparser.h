#ifndef CANINITPARSER_H
#define CANINITPARSER_H

#include "CanInitParser_global.h"
#include <caninitlexer.h>
#include <memory>
#include <stack>

namespace ciparser {
class ParseNode;
class BinExprNode;
class ExpressionNode;
class FuncCallNode;
class IdNode;
class IndexAccessNode;
class DefinitionNode;
class NumberNode;
class StructAccessNode;

class CANINITPARSER_EXPORT CanInitParser {
    using Token = CanInitLexer::Token;
    using TType = CanInitLexer::TokenType;

public:
    CanInitParser(std::unique_ptr<CanInitLexer>&& lexer)
        : lexer(std::move(lexer))
    {
        updateToken();
    }

    ParseNode* parse();

private:
    std::unique_ptr<CanInitLexer> lexer;
    Token t;
    ExpressionNode* lastExpr = nullptr;

    void updateToken()
    {
        t = lexer->nextToken();
    }

    static bool isBeginExpression(TType t)
    {
        switch (t) {
        case TType::Id:
        case TType::Number:
        case TType::LParen:
            return true;
        default:
            return false;
        }
    }

    bool isFunctionDefinition() const
    {
        auto const& next = lexer->peek();
        if ((t.type == TType::Id && next.type == TType::LParen)
            && (t.line == next.line)
            && (t.charPosInLine + t.data.size()) == next.charPosInLine)
            return true;
        else
            return false;
    }

    ParseNode* parse_p();

    BinExprNode* parseBinExpr();
    ExpressionNode* parseExpression();
    FuncCallNode* parseFuncCall();
    IdNode* parseId();
    IndexAccessNode* parseIndexAccess();
    DefinitionNode* parseDefinition();
    NumberNode* parseNumber();
    StructAccessNode* parseStructAccess();
};

}

#endif // CANINITPARSER_H
