#include "caninitvisitor.h"
#include "../Parser/binexprnode.h"
#include "../Parser/caninitnode.h"
#include "../Parser/definitionnode.h"
#include "../Parser/funccallnode.h"
#include "../Parser/funcdefnode.h"
#include "../Parser/idnode.h"
#include "../Parser/indexaccessnode.h"
#include "../Parser/numbernode.h"
#include "../Parser/parsenode.h"
#include "../Parser/structaccessnode.h"

#include "nodes/astnode.h"
#include "nodes/binexprastnode.h"
#include "nodes/caninitastnode.h"
#include "nodes/commentastnode.h"
#include "nodes/definitionastnode.h"
#include "nodes/funccallastnode.h"
#include "nodes/funcdefastnode.h"
#include "nodes/idastnode.h"
#include "nodes/indexaccessastnode.h"
#include "nodes/numberastnode.h"
#include "nodes/structaccessastnode.h"

#include "expr.h"
#include <cassert>
#include <typeinfo>

#include <utility>

using namespace ciparser;

CanInitVisitor::CanInitVisitor()
{
}

AstNode* CanInitVisitor::visit(ParseNode* n)
{
    return n->accept(this);
}

DefinitionAstNode* CanInitVisitor::visitDefinition(DefinitionNode* n)
{
    auto id = n->id();

    CommentAstNode* comment = nullptr;
    if (n->comment()) {
        comment = static_cast<CommentAstNode*>(n->comment()->accept(this));
    }
    m_currentComment = comment;

    if (n->funcDef()) {
        // To-do
        // auto func = n->funcDef()->accept(this);
    } else {
        if (!n->expr())
            return nullptr;
        auto expr = n->expr()->accept(this);
        if (auto node = dynamic_cast<BinExprAstNode*>(expr)) {
            ids.emplace(id, std::make_shared<Value>(id, node->expr(), comment));
        } else if (auto node = dynamic_cast<IdAstNode*>(expr)) {
            ids.emplace(
                    id, std::make_shared<Alias>(id, node->getName(), comment));
        } else if (auto node = dynamic_cast<NumberAstNode*>(expr)) {
            ids.emplace(
                    id,
                    std::make_shared<Value>(
                            id, new NumberExpr(node->value()), comment));
        } else if (auto node = dynamic_cast<StructAccessAstNode*>(expr)) {
            ids.emplace(id, parseMessage(node));
        } else if (auto node = dynamic_cast<IndexAccessAstNode*>(expr)) {
            // To-do Добавить парсинг cnt_*
            auto mess = parseMessage(node);
            if (mess)
                ids.emplace(id, mess);
        } else {
            assert(false);
        }
    }

    return new DefinitionAstNode(comment);
}

BinExprAstNode* CanInitVisitor::visitBinExpr(BinExprNode* n)
{
    Expr *l, *r;
    std::vector<std::string> dependencies;

    auto lNode = n->l()->accept(this);
    if (auto node = dynamic_cast<BinExprAstNode*>(lNode)) {
        l = node->expr();
        dependencies.insert(
                dependencies.end(),
                node->dependencies().begin(),
                node->dependencies().end());
    } else if (auto id = dynamic_cast<IdAstNode*>(lNode)) {
        auto alias = new Alias("", id->name(), m_currentComment);
        l = new IdExpr(alias);
        dependencies.emplace_back(id->getName());
    } else if (auto num = dynamic_cast<NumberAstNode*>(lNode)) {
        l = new NumberExpr(num->value());
    } else if (auto num = dynamic_cast<StructAccessAstNode*>(lNode)) {
        l = new MessExpr(parseMessage(num));
    } else if (auto num = dynamic_cast<IndexAccessAstNode*>(lNode)) {
        auto mess = parseMessage(num);
        assert(mess);
        l = new MessExpr(mess);
    } else {
        std::abort();
    }

    auto rNode = n->r()->accept(this);
    if (auto node = dynamic_cast<BinExprAstNode*>(rNode)) {
        r = node->expr();
        dependencies.insert(
                dependencies.end(),
                node->dependencies().begin(),
                node->dependencies().end());
    } else if (auto id = dynamic_cast<IdAstNode*>(rNode)) {
        auto alias = new Alias("", id->name(), m_currentComment);
        r = new IdExpr(alias);
        dependencies.emplace_back(id->getName());
    } else if (auto num = dynamic_cast<NumberAstNode*>(rNode)) {
        r = new NumberExpr(num->value());
    } else if (auto num = dynamic_cast<StructAccessAstNode*>(rNode)) {
        r = new MessExpr(parseMessage(num));
    } else if (auto num = dynamic_cast<IndexAccessAstNode*>(rNode)) {
        auto mess = parseMessage(num);
        assert(mess);
        r = new MessExpr(mess);
    } else {
        std::abort();
    }

    Expr* target;

    switch (n->operation()) {
    case BinExprNode::Sum:
        target = new SumExpr(l, r);
        break;
    case BinExprNode::Sub:
        target = new SubExpr(l, r);
        break;
    case BinExprNode::Mul:
        target = new MulExpr(l, r);
        break;
    case BinExprNode::Div:
        target = new DivExpr(l, r);
        break;
    case BinExprNode::And:
        target = new AndBinExpr(l, r);
        break;
    case BinExprNode::Or:
        target = new OrBinExpr(l, r);
        break;
    case BinExprNode::AndL:
        target = new AndLogicExpr(l, r);
        break;
    case BinExprNode::OrL:
        target = new OrLogicExpr(l, r);
        break;
    case BinExprNode::Eq:
        target = new EqBinExpr(l, r);
        break;
    default:
        std::abort();
    }

    return new BinExprAstNode(target, std::move(dependencies));
}

CanInitAstNode* CanInitVisitor::visitCanInit(CanInitNode* n)
{
    auto node = new CanInitAstNode;
    for (auto child : n->childrens()) {
        node->appendChild(child->accept(this));
    }

    for (auto& id : ids) {
        if (auto value = dynamic_cast<Value*>(id.second.get())) {
            value->expr()->linkId(ids);
        }
    }

    return node;
}

FuncCallAstNode* CanInitVisitor::visitFuncCall(FuncCallNode*)
{
    return nullptr;
}

IdAstNode* CanInitVisitor::visitId(IdNode* n)
{
    return new IdAstNode(n->id());
}

IndexAccessAstNode* CanInitVisitor::visitIndexAccess(IndexAccessNode* n)
{
    auto idxNode = n->index()->accept(this);
    auto object = n->expression()->accept(this);
    Expr* idx;

    if (auto node = dynamic_cast<BinExprAstNode*>(idxNode)) {
        idx = node->expr();
    } else if (auto node = dynamic_cast<NumberAstNode*>(idxNode)) {
        idx = new NumberExpr(node->value());
    } else if (auto node = dynamic_cast<IdAstNode*>(idxNode)) {
        idx = new IdExpr(new Alias("", node->getName(), m_currentComment));
    } else {
        std::abort();
    }
    return new IndexAccessAstNode(object, idx);
}

NumberAstNode* CanInitVisitor::visitNumber(NumberNode* n)
{
    return new NumberAstNode(std::stoi(n->number(), nullptr, 0));
}

StructAccessAstNode* CanInitVisitor::visitStructAccess(StructAccessNode* n)
{
    auto object = n->expr()->accept(this);
    auto idNode = dynamic_cast<IdAstNode*>(n->id()->accept(this));

    assert(idNode);

    return new StructAccessAstNode(object, idNode->getName());
}

FuncDefAstNode* CanInitVisitor::visitFuncDef(FuncDefNode*)
{
    return nullptr;
}

CommentAstNode* CanInitVisitor::visitCommentNode(CommentNode* n)
{
    return new CommentAstNode(n);
}

Message* CanInitVisitor::parseMessage(StructAccessAstNode* n)
{
    int bit;
    if (n->id() == "b0") {
        bit = 0;
    } else if (n->id() == "b1") {
        bit = 1;
    } else if (n->id() == "b2") {
        bit = 2;
    } else if (n->id() == "b3") {
        bit = 3;
    } else if (n->id() == "b4") {
        bit = 4;
    } else if (n->id() == "b5") {
        bit = 5;
    } else if (n->id() == "b6") {
        bit = 6;
    } else if (n->id() == "b7") {
        bit = 7;
    } else {
        std::abort();
    }

    auto idx = dynamic_cast<IndexAccessAstNode*>(n->object());
    assert(idx);

    int byte = idx->index()->eval();
    idx = dynamic_cast<IndexAccessAstNode*>(idx->object());
    assert(idx);

    int messId = idx->index()->eval();

    auto structNode = dynamic_cast<StructAccessAstNode*>(idx->object());
    if (!structNode)
        std::abort();

    assert(structNode->id() == "can_mes_1bit");

    auto objectNode = dynamic_cast<IdAstNode*>(structNode->object());
    if (!objectNode)
        std::abort();

    assert(objectNode->name() == "can_mes");

    return Message::bitMessage(messId, byte, bit);
}

Message* CanInitVisitor::parseMessage(IndexAccessAstNode* n)
{
    int byte;
    if (auto id = dynamic_cast<IdExpr*>(n->index())) {
        auto it = ids.find(((Alias*)(id->getId()))->getLinkName());
        assert(it != ids.end());
        auto value = dynamic_cast<Value*>(it->second.get());
        assert(value);
        byte = value->expr()->eval();
    } else {
        byte = n->index()->eval();
    }

    auto idx = dynamic_cast<IndexAccessAstNode*>(n->object());
    if (idx == nullptr) {
        auto id = dynamic_cast<IdAstNode*>(n->object());
        if (id)
            return nullptr;
    }
    if (!idx)
        std::abort();

    int messId;
    if (auto id = dynamic_cast<IdExpr*>(idx->index())) {
        auto it = ids.find(((Alias*)(id->getId()))->getLinkName());
        assert(it != ids.end());
        auto value = dynamic_cast<Value*>(it->second.get());
        assert(value);
        messId = value->expr()->eval();
    } else {
        messId = idx->index()->eval();
    }

    auto structNode = dynamic_cast<StructAccessAstNode*>(idx->object());

    Message::Type type;
    if (structNode->id() == "can_mes_char") {
        if (!m_currentComment) {
            type = Message::Uint8;
        } else {
            auto sign = m_currentComment->attribute("sign");
            if (sign == nullptr)
                type = Message::Uint8;
            else if (*sign == "unsigned")
                type = Message::Uint8;
            else if (*sign == "signed")
                type = Message::Int8;
            else {
                std::abort();
            }
        }
    } else if (structNode->id() == "can_mes_int") {
        if (!m_currentComment) {
            type = Message::Uint16;
        } else {
            auto sign = m_currentComment->attribute("sign");
            if (sign == nullptr)
                type = Message::Uint16;
            else if (*sign == "unsigned")
                type = Message::Uint16;
            else if (*sign == "signed")
                type = Message::Int16;
            else {
                std::abort();
            }
        }
    } else {
        std::abort();
    }

    auto objectNode = dynamic_cast<IdAstNode*>(structNode->object());
    if (!objectNode)
        std::abort();

    assert(objectNode->name() == "can_mes");

    return Message::intMessage(type, messId, byte);
}
