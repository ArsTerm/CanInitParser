#pragma once

#include "types/message.h"
#include <cassert>
#include <optional>
#include <string>
#include <unordered_map>

namespace ciparser {
class Expr {
public:
    virtual int eval() = 0;
    virtual std::optional<Id::UnwrapResult> linkId(Id::Set const&) = 0;
    virtual void setSign(bool sign) = 0;
    virtual Message::Type type() = 0;
    virtual ~Expr() = default;
};

class MessExpr final : public Expr {
public:
    int eval() override;

    Message* message()
    {
        return &mess;
    }

    std::optional<Id::UnwrapResult> linkId(Id::Set const&) override
    {
        return std::nullopt;
    }

    MessExpr(Message const* m) : mess(*m)
    {
    }

private:
    Message mess;

    // Expr interface
public:
    void setSign(bool sign) override;
    Message::Type type() override;
};

class IdExpr final : public Expr {
public:
    int eval() override;

    std::optional<Id::UnwrapResult> linkId(Id::Set const& set) override
    {
        return id->unwrap(set);
    }

    Id* getId() const
    {
        return id;
    }

    IdExpr(Id* id) : id(id)
    {
    }

private:
    Id* id;

    // Expr interface
public:
    void setSign(bool sign) override;
    Message::Type type() override;
};

class NumberExpr final : public Expr {
public:
    int eval() override;

    std::optional<Id::UnwrapResult> linkId(Id::Set const&) override
    {
        return std::nullopt;
    }

    NumberExpr(int val) : value(val)
    {
    }

public:
    int value;

    // Expr interface
public:
    void setSign(bool sign) override;
    Message::Type type() override;
};

class BinaryExpr : public Expr {
public:
    BinaryExpr(Expr* l, Expr* r) : l(l), r(r)
    {
    }

    Expr* left() const
    {
        return l;
    }

    Expr* rigth() const
    {
        return r;
    }

    std::optional<Id::UnwrapResult> linkId(Id::Set const& set) override;
    ~BinaryExpr() override;

protected:
    Expr* l;
    Expr* r;

public:
    void setSign(bool sign) override;
    Message::Type type() override;
};

class SumExpr final : public BinaryExpr {
public:
    int eval() override;

    SumExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class SubExpr final : public BinaryExpr {
public:
    int eval() override;

    SubExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class MulExpr final : public BinaryExpr {
public:
    int eval() override;

    MulExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class DivExpr final : public BinaryExpr {
public:
    int eval() override;

    DivExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class AndBinExpr final : public BinaryExpr {
public:
    int eval() override;

    AndBinExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class OrBinExpr final : public BinaryExpr {
public:
    int eval() override;

    OrBinExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class AndLogicExpr final : public BinaryExpr {
public:
    int eval() override;

    AndLogicExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class OrLogicExpr final : public BinaryExpr {
public:
    int eval() override;

    OrLogicExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};

class EqBinExpr final : public BinaryExpr {
public:
    int eval() override;

    EqBinExpr(Expr* l, Expr* r) : BinaryExpr(l, r)
    {
    }
};
}
