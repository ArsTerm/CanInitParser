#include <Visitor/caninitastnode.h>
#include <Visitor/caninitvisitor.h>
#include <caninitlexer.h>
#include <caninitnode.h>
#include <caninitparser.h>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    //    auto f = fopen("C:\\Projects\\CanInitParser\\CanInit.h", "r");
    //    fseek(f, 0, SEEK_END);
    //    auto dataSize = ftell(f);
    //    fseek(f, 0, SEEK_SET);

    //    auto str = new char[dataSize + 1];
    //    str[dataSize] = '\0';
    //    auto dsize = fread(str, 1, dataSize, f);
    //    dataSize = dsize;

    // ciparser::CanInitLexer lexer(str, dataSize);

    auto str = "#define BIT2(x, offset) a + b * c - d / 4";
    auto dataSize = strlen(str);

    ciparser::CanInitParser parser(
            std::make_unique<ciparser::CanInitLexer>(str, dataSize));

    auto d = (ciparser::CanInitNode*)parser.parse();

    std::cout << "Tree root: " << d << std::endl;

    ciparser::CanInitVisitor visitor(d);

    visitor.parse();
    //    auto t = lexer.nextToken();
    //    while (t.type != ciparser::CanInitLexer::Eof) {
    //        std::cout << lexer.tokenToString(t) << std::endl;
    //        t = lexer.nextToken();
    //    }

    return 0;
}
