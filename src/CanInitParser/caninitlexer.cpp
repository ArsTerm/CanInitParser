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

    while (*data == ' ' || *data == '\t') {
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
    case '?':
        token = generate(QuestionMark, std::string_view(data, 1));
        break;
    case '"':
        token = generate(QuotationMark, std::string_view(data, 1));
        break;
    case '\'':
        token = generate(Apostrophe, std::string_view(data, 1));
        break;
    case '/':
        if (*(data + 1) == '/') {
            token = generate(CommentLine, std::string_view(data, 2));
        } else if (*(data + 1) == '*') {
            token = generate(CommentBegin, std::string_view(data, 2));
        } else {
            token = generate(LSlash, std::string_view(data, 1));
        }
        break;
    case '\\':
        if (*(data + 1) == '\r' && *(data + 2) == '\n') {
            line++;
            charPosInLine = 0;
            data += 2;
        } else if (*(data + 1) == '\n') {
            line++;
            charPosInLine = 0;
            data++;
        }
        data++;
        charPosInLine++;
        tokenize();
        break;
    case '\r':
        if (*(data + 1) == '\n') {
            token = generate(LineFeed, std::string_view(data, 2));
            line++;
            charPosInLine = 1;
        } else {
            data++;
            charPosInLine++;
        }
        break;
    case '\n':
        token = generate(LineFeed, std::string_view(data, 1));
        line++;
        charPosInLine = 1;
        break;
    case '+':
        if (*(data + 1) == '+')
            token = generate(Increment, std::string_view(data, 2));
        else
            token = generate(Plus, std::string_view(data, 1));
        break;
    case '-':
        if (*(data + 1) == '-')
            token = generate(Decrement, std::string_view(data, 2));
        else
            token = generate(Minus, std::string_view(data, 1));
        break;
    case '&':
        if (*(data + 1) == '&')
            token = generate(AndLogic, std::string_view(data, 2));
        else
            token = generate(And, std::string_view(data, 1));
        break;
    case '|':
        if (*(data + 1) == '|')
            token = generate(OrLogic, std::string_view(data, 2));
        else
            token = generate(Or, std::string_view(data, 1));
        break;
    case '^':
        token = generate(Xor, std::string_view(data, 1));
        break;
    case '=':
        if (*(data + 1) == '=')
            token = generate(Equal, std::string_view(data, 2));
        else
            token = generate(Assign, std::string_view(data, 1));
        break;
    case '@':
        if (*(data + 1) == '*') {
            token = generate(AttributeBegin, std::string_view(data, 2));
        } else {
            std::terminate();
        }
        break;
    case '*':
        if (*(data + 1) == '@') {
            token = generate(AttributeEnd, std::string_view(data, 2));
        } else if (*(data + 1) == '/') {
            token = generate(CommentEnd, std::string_view(data, 2));
        } else {
            token = generate(Asterisk, std::string_view(data, 1));
        }
        break;
    case '!':
        if (*(data + 1) == '=')
            token = generate(NotEqual, std::string_view(data, 2));
        else
            token = generate(Exclamation, std::string_view(data, 1));
        break;
    case '~':
        token = generate(Tilda, std::string_view(data, 1));
        break;
    case '%':
        token = generate(Percent, std::string_view(data, 1));
        break;
    case '<': {
        auto next = *(data + 1);
        if (next == '=')
            token = generate(LessOrEq, std::string_view(data, 2));
        else if (next == '<')
            token = generate(LShift, std::string_view(data, 2));
        else
            token = generate(LTriangle, std::string_view(data, 1));
        break;
    }
    case '>': {
        auto next = *(data + 1);
        if (next == '=')
            token = generate(MoreOrEq, std::string_view(data, 2));
        else if (next == '>')
            token = generate(RShift, std::string_view(data, 2));
        else
            token = generate(RTriangle, std::string_view(data, 1));
        break;
    }
    case ',':
        token = generate(Comma, std::string_view(data, 1));
        break;
    default:
        if (isCirillicAlpha(*data) || std::isalpha(*data) || *data == '_')
            tokenizeId();
        else if (isdigit(*data))
            tokenizeNumber();
        else {
            char val = *data;
            auto curr = currPos();
            auto end = eof();
            std::cerr << "Undefined value: " << val << " Position: " << curr
                      << " eof: " << end << "\n";
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
    if (isCirillicAlpha(*data))
        data++;
    data++;
    while (isCirillicAlpha(*data) || std::isalpha(*data) || isdigit(*data)
           || *data == '_') {
        if (isCirillicAlpha(*data))
            data++;
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
        if (isCirillicAlpha(*data)) {
            break;
        } else if (isdigit(*data)) {
            data++;
            continue;
        } else if (isHex) {
            auto c = toupper(*data);
            if (c >= 'A' && c <= 'F') {
                data++;
                continue;
            }
        }
        break;
    }
    token = generate(Number, std::string_view(begin, data - begin), false);
}
