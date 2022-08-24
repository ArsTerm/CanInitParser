#ifndef CANINITLEXER_H
#define CANINITLEXER_H

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
        Comma
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
        return currPos() == dataSize;
    }

    void tokenize();

    void tokenizeDefine();
    void tokenizeId();
    void tokenizeNumber();
    void skipCommentLine();
    void skipBigComment();

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

#endif // CANINITLEXER_H
