#pragma once

#include "CanInitParser_global.h"
#include <string>
#include <string_view>

namespace ciparser {
class CANINITPARSER_EXPORT CanInitLexer {
public:
    enum TokenType {
        Eof = -1,
        DefineKw,
        LParen,
        RParen,
        Dot,
        LSlash,
        RSlash,
        LSquare,
        RSquare,
        Id,
        Number,
        LineFeed,
        Plus,
        Minus,
        And,
        Or,
        Equal,
        Assign,
        Increment,
        Decrement,
        Asterisk,
        Exclamation,
        AndLogic,
        OrLogic,
        Xor,
        NotEqual,
        Tilda,
        Percent,
        Comma,
        LTriangle,
        RTriangle,
        LessOrEq,
        MoreOrEq,
        LShift,
        RShift,
        CommentLine,
        CommentBegin,
        CommentEnd,
        AttributeBegin,
        AttributeEnd,
        QuestionMark,
        QuotationMark,
        Apostrophe
    };

    static constexpr char const* typeToString(TokenType const& t)
    {
#define TYPE_CASE(t) \
    case t:          \
        return #t;

        switch (t) {
            TYPE_CASE(Eof)
            TYPE_CASE(DefineKw)
            TYPE_CASE(LParen)
            TYPE_CASE(RParen)
            TYPE_CASE(Dot)
            TYPE_CASE(LSlash)
            TYPE_CASE(RSlash)
            TYPE_CASE(LSquare)
            TYPE_CASE(RSquare)
            TYPE_CASE(Id)
            TYPE_CASE(Number)
            TYPE_CASE(LineFeed)
            TYPE_CASE(Plus)
            TYPE_CASE(Minus)
            TYPE_CASE(And)
            TYPE_CASE(Or)
            TYPE_CASE(Equal)
            TYPE_CASE(Comma)
            TYPE_CASE(Assign)
            TYPE_CASE(Increment)
            TYPE_CASE(Decrement)
            TYPE_CASE(Asterisk)
            TYPE_CASE(Exclamation)
            TYPE_CASE(AndLogic)
            TYPE_CASE(OrLogic)
            TYPE_CASE(Xor)
            TYPE_CASE(NotEqual)
            TYPE_CASE(Tilda)
            TYPE_CASE(Percent)
            TYPE_CASE(LTriangle)
            TYPE_CASE(RTriangle)
            TYPE_CASE(LessOrEq)
            TYPE_CASE(MoreOrEq)
            TYPE_CASE(LShift)
            TYPE_CASE(RShift)
            TYPE_CASE(CommentLine)
            TYPE_CASE(CommentBegin)
            TYPE_CASE(CommentEnd)
            TYPE_CASE(AttributeBegin)
            TYPE_CASE(AttributeEnd)
            TYPE_CASE(QuestionMark)
            TYPE_CASE(QuotationMark)
            TYPE_CASE(Apostrophe)
        default:
            std::terminate();
        }
    }

    struct Token {
        TokenType type = Eof;
        std::string_view data;
        int charPosInLine;
        int line;

        operator std::string() const
        {
            std::string result("<");
            result += std::to_string(line);
            result += ":";
            result += std::to_string(charPosInLine);
            result += "> ";
            result += typeToString(type);
            result += " = ";
            if (type == LineFeed)
                result += "\\n";
            else
                result += data;

            return result;
        }
        friend bool operator==(Token const& t1, Token const& t2)
        {
            return t1.type == t2.type && t1.charPosInLine == t2.charPosInLine
                    && t1.line == t2.line;
        }
        friend bool operator!=(Token const& t1, Token const& t2)
        {
            return !(t1 == t2);
        }
    };

    static std::string tokenToString(Token const& t)
    {
        return std::string(t);
    }

    Token nextToken()
    {
        auto result = token;
        tokenize();
        return result;
    }

    Token const& peek() const
    {
        return token;
    }

    CanInitLexer(char const* data, size_t dataSize)
        : dataBegin(data), data(data), dataSize(dataSize)
    {
        tokenize();
    }

private:
    Token token;
    char const* const dataBegin;
    char const* data;
    size_t dataSize;
    int line = 1;
    int charPosInLine = 1;

    size_t currPos() const
    {
        return data - dataBegin;
    }

    bool eof() const
    {
        return currPos() >= dataSize;
    }

    void tokenize();

    void tokenizeDefine();
    void tokenizeId();
    void tokenizeNumber();

    static bool isCirillicAlpha(uint8_t val)
    {
        return val == 0xd0 || val == 0xd1;
    }

    Token
    generate(TokenType type, std::string_view data, bool needOffsetData = true)
    {
        Token t;
        t.type = type;
        t.data = data;
        t.charPosInLine = charPosInLine;
        t.line = line;

        charPosInLine += data.size();
        if (needOffsetData)
            this->data += data.size();

        return t;
    }
};
}
