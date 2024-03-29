#include <Context/context.h>
#include <Parser/caninitnode.h>
#include <Parser/caninitparser.h>
#include <Visitor/caninitvisitor.h>
#include <Visitor/nodes/astnode.h>
#include <caninitlexer.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

int main()
{
    auto file
            = "C:\\Projects\\BlackBoxViewer\\external\\CanInitParser\\CanInit."
              "h";
    //    auto f = fopen(file, "r");
    //    fseek(f, 0, SEEK_END);
    //    auto dataSize = ftell(f);
    //    fseek(f, 0, SEEK_SET);

    //    auto str = new char[dataSize + 1];
    //    str[dataSize] = '\0';
    //    auto dsize = fread(str, 1, dataSize, f);
    //    dataSize = dsize;

    // ciparser::CanInitLexer lexer(str, dataSize);

    auto str
            = "#define I_Can I_92frn // @* sign = signed *@\n"
              "#define I_92frn can_mes.can_mes_char[62][0] // @* sign = "
              "unsigned "
              "*@\n";
    auto dataSize = strlen(str);

    ciparser::CanInitParser parser(
            std::make_unique<ciparser::CanInitLexer>(str, dataSize));

    auto d = (ciparser::CanInitNode*)parser.parse();

    //   std::cout << "Tree root: " << d << std::endl;
    std::cout << "Tree json:\n" << d->toJson(0) << std::endl;

    ciparser::CanInitVisitor visitor;

    auto ast = visitor.visit(d);

    std::cout << "\nAst count: " << ast->children().size() << '\n';

    ciparser::BBFrame frames[4];

    frames[0].time = ciparser::BBTime();
    frames[0].id = 26;
    frames[0].data = {0, 0, 0, 0, 0, 0, 0, 0};

    frames[1].time = ciparser::BBTime(frames[0].time, 1);
    frames[1].id = 26;
    frames[1].data = {15, 15, 15, 15, 15, 15, 15, 15};

    frames[2].time = ciparser::BBTime(frames[0].time, 2);
    frames[2].id = 26;
    frames[2].data = {101, 101, 101, 101, 101, 101, 101, 101};

    frames[3].time = ciparser::BBTime(frames[0].time, 5);
    frames[3].id = 26;
    frames[3].data = {126, 126, 126, 126, 126, 126, 126, 126};

    ciparser::Context context(frames, 4, visitor.get_ids());

    auto handle = context.handle("Door1_State");
    for (int i = 0; i < 7; i++) {
        std::cout << "Value: " << *handle << '\n';
        context.incTick();
    }

    std::cout << "Dec:\n";
    for (int i = 0; i < 7; i++) {
        std::cout << "Value: " << *handle << std::endl;
        // context.decTick();
    }
    return 0;
}
