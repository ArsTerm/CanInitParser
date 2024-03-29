#pragma once

#include "../CanInitParser_global.h"
#include "../caninitlexer.h"
#include <cassert>
#include <memory>
#include <stack>
#include <vector>

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
class FuncDefNode;
class CommentNode;

class CANINITPARSER_EXPORT CanInitParser {
    using Token = CanInitLexer::Token;
    using TType = CanInitLexer::TokenType;
#undef EXPORT
public:
    CanInitParser(std::unique_ptr<CanInitLexer>&& lexer);

    ParseNode* parse();

private:
    struct OperationInfo {
        Token t;
        bool unary;
        OperationInfo() = default;
        explicit OperationInfo(Token&& t, bool unary = false)
            : t(std::move(t)), unary(unary)
        {
        }
        explicit OperationInfo(Token const& t, bool unary = false)
            : t(t), unary(unary)
        {
        }
    };
    std::unique_ptr<CanInitLexer> lexer;
    Token t;
    Token prev;
    std::stack<ParseNode*> stackNodes;
    std::stack<OperationInfo> stackOperators;

    void updateToken();
    void pushBracket();
    void parseStack();

    static void
    parseStack(std::stack<ParseNode*>& n, std::stack<OperationInfo>& op);

    void offloadAll();
    static void
    offloadAll(std::stack<ParseNode*>& n, std::stack<OperationInfo>& op);

    void offloadStack(int priority);

    static void offloadStack(
            std::stack<ParseNode*>& n,
            std::stack<OperationInfo>& op,
            int priority);

    bool offloadBracket();
    static void offloadUntil(
            std::stack<ParseNode*>& n,
            std::stack<OperationInfo>& op,
            TType type);
    void offloadUntil(TType type);

    static ParseNode*
    parse_p(Token const& operation, ParseNode* l, ParseNode* r);
    static ParseNode* parse_p(Token const& operation, ParseNode* n);

    static constexpr int operatorPriority(TType type, bool unary = false);

    static bool isBeginExpression(TType t);

    bool isFunctionDefinition() const;

    ParseNode* parse_p();

    FuncDefNode* parseFuncDef();
    CommentNode* parseComment();
    ParseNode* parseExpression(TType end = TType::Eof);
    IdNode* parseId();
    NumberNode* parseNumber();
    FuncCallNode* parseFuncCall();
    static BinExprNode*
    parseBinExpr(ParseNode* l, ParseNode* r, Token const& delim);
    static IndexAccessNode* parseIndexAccess(ParseNode* l, ParseNode* r);
    static StructAccessNode* parseStructAccess(ParseNode* l, ParseNode* r);
    DefinitionNode* parseDefinition();
};

}
