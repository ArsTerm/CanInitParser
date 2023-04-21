#include "compiler.h"
#include <Parser/caninitnode.h>
#include <Parser/caninitparser.h>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <Visitor/caninitvisitor.h>
#include <Visitor/expr.h>
#include <Visitor/nodes/astnode.h>
#include <Visitor/types/alias.h>
#include <Visitor/types/aliasmessage.h>
#include <Visitor/types/message.h>
#include <Visitor/types/value.h>
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

    parseSet(visitor.get_ids(), outFile);

    delete parseNode;
    delete astNode;

    return 0;
}

std::optional<std::pair<void*, size_t>>
Compiler::readFile(std::string_view file)
{
    auto f = fopen(file.data(), "rb");
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

QJsonObject exprToJson(ciparser::Expr* expr)
{
    QJsonObject result;

    if (auto binExpr = dynamic_cast<ciparser::BinaryExpr*>(expr)) {
        result.insert("type", "binary");
        result.insert("left", exprToJson(binExpr->left()));
        result.insert("right", exprToJson(binExpr->rigth()));
        result.insert("operation", binExpr->opName());
    } else if (auto messExpr = dynamic_cast<ciparser::MessExpr*>(expr)) {
        auto message = messExpr->message();
        result.insert("type", "message");
        result.insert("messType", message->type());
        result.insert("messId", message->messId());
        result.insert("messOffset", message->offset());
        result.insert("messBit", message->bit());
    } else if (auto idExpr = dynamic_cast<ciparser::IdExpr*>(expr)) {
        result.insert("type", "id");
        result.insert("name", idExpr->getId()->name().c_str());
    } else if (auto numberExpr = dynamic_cast<ciparser::NumberExpr*>(expr)) {
        result.insert("type", "number");
        result.insert("value", numberExpr->eval());
    }

    return result;
}

void Compiler::parseSet(const ciparser::Id::Set& s, std::string_view outFile)
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
        } else if (
                auto aliasMessage
                = dynamic_cast<const ciparser::AliasMessage*>(id.get())) {
            result.append(QJsonObject{
                    {"type", "aliasMessage"},
                    {"name", aliasMessage->name().c_str()},
                    {"messType", (int)aliasMessage->message()->type()},
                    {"messId", aliasMessage->message()->messId()},
                    {"messOffset", aliasMessage->message()->offset()},
                    {"messBit", aliasMessage->message()->bit()}});
        } else if (
                auto message
                = dynamic_cast<const ciparser::Message*>(id.get())) {
            result.append(QJsonObject{
                    {"type", "message"},
                    {"messType", message->type()},
                    {"messId", message->messId()},
                    {"messOffset", message->offset()},
                    {"messBit", message->bit()}});
        } else if (
                auto value = dynamic_cast<const ciparser::Value*>(id.get())) {
            result.append(QJsonObject{
                    {"type", "value"},
                    {"id", value->id().c_str()},
                    {"expression", exprToJson(value->expr())}});
        }
    }

    QJsonDocument obj(result);
    QFile file(outFile.data());

    file.open(QFile::WriteOnly | QFile::Text);
    file.write(obj.toJson());
}

}
