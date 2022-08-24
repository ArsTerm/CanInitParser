#include "caninitlexer.h"
#include <cassert>
#include <cctype>

#include <iostream>

using ciparser::CanInitLexer;

void CanInitLexer::tokenize()
{
    if (eof()) {
        token = Token();
        return;
    }

    while (*data == ' ') {
        data++;
        charPosInLine++;
    }

    switch (*data) {
    case '#':
        tokenizeDefine();
        break;
    case '(':
        token = generate(LParen, std::string_view(data, 1));
        break;
    case ')':
        token = generate(RParen, std::string_view(data, 1));
        break;
    case '.':
        token = generate(Dot, std::string_view(data, 1));
        break;
    case '[':
        token = generate(LSquare, std::string_view(data, 1));
        break;
    case ']':
        token = generate(RSquare, std::string_view(data, 1));
        break;
    case '/':
        if (*(data + 1) == '/') {
            skipCommentLine();
            token = generate(LineFeed, std::string_view(data - 1, 1), false);
        } else if (*(data + 1) == '*') {
            auto oldLine = line;
            skipBigComment();
            if (oldLine != line) {
                token = generate(
                        LineFeed, std::string_view(data - 1, 1), false);
            } else
                tokenize();
        } else {
            token = generate(LSlash, std::string_view(data, 1));
        }
        break;
    case '\\':
        if (*(data + 1) == '\n') {
            line++;
            charPosInLine = 0;
            data++;
        }
        data++;
        charPosInLine++;
        tokenize();
        break;
    case '\n':
        token = generate(LineFeed, std::string_view(data, 1));
        line++;
        charPosInLine = 1;
        break;
    case '+':
        token = generate(Plus, std::string_view(data, 1));
        break;
    case '-':
        token = generate(Minus, std::string_view(data, 1));
        break;
    case '&':
        token = generate(And, std::string_view(data, 1));
        break;
    case '|':
        token = generate(Or, std::string_view(data, 1));
        break;
    case '=':
        token = generate(Equal, std::string_view(data, 1));
        break;
    case ',':
        token = generate(Comma, std::string_view(data, 1));
        break;
    default:
        if (isalpha(*data) || *data == '_')
            tokenizeId();
        else if (isdigit(*data))
            tokenizeNumber();
        else {
            assert(false);
        }
    }
}

void CanInitLexer::tokenizeDefine()
{
    auto test = std::string_view(data, 7);
    auto test2 = std::string_view(data, 6);

    if (test == "#define")
        token = generate(DefineKw, test);
    else if (test == "#ifndef") {
        charPosInLine += 7;
        data += 7;
        tokenize();
    } else if (test2 == "#ifdef") {
        charPosInLine += 6;
        data += 6;
        tokenize();
    } else if (test2 == "#endif") {
        charPosInLine += 6;
        data += 6;
        tokenize();
    } else {
        assert(false);
    }
}

void CanInitLexer::tokenizeId()
{
    auto begin = data;
    data++;
    while (isalpha(*data) || isdigit(*data) || *data == '_') {
        data++;
    }
    token = generate(Id, std::string_view(begin, data - begin), false);
}

void CanInitLexer::tokenizeNumber()
{
    auto begin = data;
    data++;
    bool isHex = false;
    if (*data == 'b')
        data++;
    else if (*data == 'x') {
        data++;
        isHex = true;
    }

    while (true) {
        if (isdigit(*data)) {
            data++;
            continue;
        } else if (isHex) {
            auto c = toupper(*data);
            if (c >= 'A' && c <= 'F') {
                data++;
                continue;
            }
        }
        assert(!isalpha(*data));
        break;
    }
    token = generate(Number, std::string_view(begin, data - begin), false);
}

void CanInitLexer::skipCommentLine()
{
    while (*data != '\n')
        data++;
    data++;
    line++;
    charPosInLine = 1;
}

void CanInitLexer::skipBigComment()
{
    data += 2;
    while (std::string_view(data, 2) != "*/") {
        if (*data == '\n') {
            line++;
            charPosInLine = 1;
        }
        data++;
        charPosInLine++;
    }
    data += 2;
    charPosInLine += 2;

    std::cerr << "Skip big comment on: <" << line << ':' << charPosInLine
              << "> " << '\n';
}
