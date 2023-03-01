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

}
