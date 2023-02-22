#pragma once

#include "types/message.h"
#include <cassert>
#include <string>
#include <unordered_map>

namespace ciparser {
class Expr {
public:
    virtual int eval() = 0;
    virtual Id::UnwrapResult linkId(Id::Set const&) = 0;
};

class MessExpr final : public Expr {
public:
    int eval() override
    {
        if (mess->type() == Message::Bit)
            return mess->bitValue();
        if (mess->type() == Message::Int8)
            return mess->value<int8_t>();
        if (mess->type() == Message::Uint8)
            return mess->value<uint8_t>();
        if (mess->type() == Message::Int16)
            return mess->value<int16_t>();
        if (mess->type() == Message::Uint16)
            return mess->value<uint16_t>();
        assert(false);
        return 0;
    }

    Id::UnwrapResult linkId(Id::Set const&) override
    {
        return Id::UnwrapResult();
    }

    MessExpr(Message const* m) : mess(m)
    {
    }

private:
    Message const* mess;
};

class IdExpr final : public Expr {
public:
    int eval() override
    {
        assert(false);
        return 0;
    }

    Id::UnwrapResult linkId(Id::Set const& set) override
    {
        return id->unwrap(set);
    }

    IdExpr(Id* id) : id(id)
    {
    }

private:
    Id* id;
};

class NumberExpr final : public Expr {
public:
    int eval() override
    {
        return value;
    }

    Id::UnwrapResult linkId(Id::Set const& set) override
    {
        return Id::UnwrapResult();
    }

    NumberExpr(int val) : value(val)
    {
    }

public:
    int value;
};

class BinaryExpr : public Expr {
public:
    BinaryExpr(Expr* l, Expr* r) : l(l), r(r)
    {
    }

    Id::UnwrapResult linkId(Id::Set const& set) override;

protected:
    Expr* l;
    Expr* r;
};

class SumExpr final : public BinaryExpr {
public:
    int eval() override
    {
        return l->eval() + r->eval();
    }

    SumExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class SubExpr final : public BinaryExpr {
public:
    int eval() override
    {
        return l->eval() - r->eval();
    }

    SubExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class MulExpr final : public BinaryExpr {
public:
    int eval() override
    {
        return l->eval() * r->eval();
    }

    MulExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class DivExpr final : public BinaryExpr {
public:
    int eval() override
    {
        return l->eval() / r->eval();
    }

    DivExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class AndBinExpr final : public BinaryExpr {
public:
    int eval() override
    {
        return l->eval() & r->eval();
    }

    AndBinExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};
}
