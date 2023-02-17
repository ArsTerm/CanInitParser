#include <Parser/caninitnode.h>
#include <Parser/caninitparser.h>
#include <Visitor/caninitvisitor.h>
#include <caninitlexer.h>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    auto file = "\\\\wsl.localhost\\Debian\\home\\gleb\\Programms\\Indicator-program\\src\\indicator-program\\can\\CanInit.h";
    auto f = fopen(file, "r");
        fseek(f, 0, SEEK_END);
        auto dataSize = ftell(f);
        fseek(f, 0, SEEK_SET);

        auto str = new char[dataSize + 1];
        str[dataSize] = '\0';
        auto dsize = fread(str, 1, dataSize, f);
        dataSize = dsize;

    // ciparser::CanInitLexer lexer(str, dataSize);

//    auto str = "#define Door1_Open (((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Open) || ((can_mes_can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Open_))";
//    auto dataSize = strlen(str);

    ciparser::CanInitParser parser(
            std::make_unique<ciparser::CanInitLexer>(str, dataSize));

    auto d = (ciparser::CanInitNode*)parser.parse();

    std::cout << "Tree root: " << d << std::endl;
    std::cout << "Tree json:\n" << d->toJson(0);

//    ciparser::CanInitVisitor visitor(d);

//    visitor.parse();
    //    auto t = lexer.nextToken();
    //    while (t.type != ciparser::CanInitLexer::Eof) {
    //        std::cout << lexer.tokenToString(t) << std::endl;
    //        t = lexer.nextToken();
    //    }

    return 0;
}
