#include "compiler.h"
#include <Parser/caninitnode.h>
#include <Parser/caninitparser.h>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <Visitor/caninitvisitor.h>
#include <Visitor/nodes/astnode.h>
#include <Visitor/types/alias.h>
#include <caninitlexer.h>
#include <cstdio>

namespace cicompiler {

int Compiler::compile(std::string_view inFile, std::string_view outFile)
{
    auto res = readFile(inFile);
    if (!res)
        return -1;
    auto [data, len] = *res;

    ciparser::CanInitParser parser(
            std::make_unique<ciparser::CanInitLexer>((const char*)data, len));

    ciparser::CanInitVisitor visitor;

    auto parseNode = parser.parse();
    auto astNode = visitor.visit(parseNode);
}

std::optional<std::pair<void*, size_t>>
Compiler::readFile(std::string_view file)
{
    auto f = fopen(file.data(), "r");
    if (!f)
        return std::nullopt;

    fseek(f, 0, SEEK_END);
    auto fSize = ftell(f);
    fseek(f, 0, SEEK_SET);

    auto data = new char[fSize];
    fread(data, 1, fSize, f);
    fclose(f);

    return std::make_pair(data, (size_t)fSize);
}

void Compiler::freeFile(void* data)
{
    delete[](char*) data;
}

void Compiler::parseSet(const ciparser::Id::Set& s)
{
    QJsonArray result;

    for (auto& [name, id] : s) {
        if (auto alias = dynamic_cast<const ciparser::Alias*>(id.get())) {
            QJsonObject obj;

            for (auto& val : alias->attribs) {
                obj.insert(val.first.c_str(), val.second.c_str());
            }
            result.append(QJsonObject{
                    {"type", "alias"},
                    {"name", alias->m_name.c_str()},
                    {"linkName", alias->m_name.c_str()},
                    {"comment", alias->comment.c_str()},
                    {"attributes", obj}});
        }
    }
}

}
