#include "expr.h"
#include "types/value.h"

namespace ciparser {
std::optional<Id::UnwrapResult> BinaryExpr::linkId(Id::Set const& set)
{
    auto opt = l->linkId(set);
    if (opt.has_value()) {
        auto ret = opt.value();
        if (ret.index() == 0) {
            l = new MessExpr(std::get<0>(ret));
        } else if (ret.index() == 1) {
            auto val = std::get<1>(ret);
            l = val->expr();
            l->linkId(set);
        }
    }

    opt = r->linkId(set);
    if (opt.has_value()) {
        auto ret = opt.value();
        if (ret.index() == 0) {
            r = new MessExpr(std::get<0>(ret));
        } else if (ret.index() == 1) {
            auto val = std::get<1>(ret);
            r = val->expr();
            r->linkId(set);
        }
    }

    return std::nullopt;
}

BinaryExpr::~BinaryExpr()
{
    delete r;
    delete l;
}

int MessExpr::eval()
{
    if (mess.type() == Message::Bit)
        return mess.bitValue();
    if (mess.type() == Message::Int8)
        return mess.value<int8_t>();
    if (mess.type() == Message::Uint8)
        return mess.value<uint8_t>();
    if (mess.type() == Message::Int16)
        return mess.value<int16_t>();
    if (mess.type() == Message::Uint16)
        return mess.value<uint16_t>();
    assert(false);
    return 0;
}

int IdExpr::eval()
{
    assert(false);
    return 0;
}

int NumberExpr::eval()
{
    return value;
}

int SumExpr::eval()
{
    return l->eval() + r->eval();
}

int SubExpr::eval()
{
    return l->eval() - r->eval();
}

int MulExpr::eval()
{
    return l->eval() * r->eval();
}

int DivExpr::eval()
{
    return l->eval() / r->eval();
}

int AndBinExpr::eval()
{
    return l->eval() & r->eval();
}

int OrBinExpr::eval()
{
    return l->eval() | r->eval();
}

int AndLogicExpr::eval()
{
    return l->eval() && r->eval();
}

int OrLogicExpr::eval()
{
    return l->eval() || r->eval();
}

int EqBinExpr::eval()
{
    return l->eval() == r->eval();
}

void ciparser::MessExpr::setSign(bool sign)
{
    switch (mess.type()) {
    case Message::Int16:
    case Message::Uint16:
        mess.setType(sign ? Message::Int16 : Message::Uint16);
        break;
    case Message::Int8:
    case Message::Uint8:
        mess.setType(sign ? Message::Int8 : Message::Uint8);
        break;
    default:
        break;
    }
}

Message::Type ciparser::MessExpr::type()
{
    return mess.type();
}

void ciparser::IdExpr::setSign(bool)
{
    std::terminate();
}

Message::Type ciparser::IdExpr::type()
{
    std::terminate();
}

void ciparser::NumberExpr::setSign(bool)
{
}

Message::Type ciparser::NumberExpr::type()
{
    if (value < 0) {
        if (value > -128)
            return Message::Int8;
        return Message::Int16;
    } else {
        if (value < 128)
            return Message::Int8;
        if (value < 256)
            return Message::Uint8;
        if (value < 32768)
            return Message::Int16;
        return Message::Uint16;
    }
}

void ciparser::BinaryExpr::setSign(bool sign)
{
    l->setSign(sign);
    r->setSign(sign);
}

namespace {
int typeSize(Message::Type l)
{
    switch (l) {
    case Message::Bit:
        return 0;
    case Message::Int8:
        return 1;
    case Message::Uint8:
        return 2;
    case Message::Int16:
        return 3;
    case Message::Uint16:
        return 4;
    }
}
}

Message::Type ciparser::BinaryExpr::type()
{
    auto lt = l->type();
    auto rt = r->type();

    return typeSize(lt) > typeSize(rt) ? lt : rt;
}

}
