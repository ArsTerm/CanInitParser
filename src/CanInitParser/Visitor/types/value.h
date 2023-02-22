#pragma once

#include "id.h"
#include <string>
#include <vector>

namespace ciparser {
class Message;
class Expr;
class Value : public Id {
public:
    std::string const& id() const
    {
        return m_id;
    }

    Expr* expr() const
    {
        return m_expr;
    }

    UnwrapResult unwrap(Set const&) const override;
    std::string const& name() const override;

    Value(std::string_view id, Expr* expr) : m_id(id), m_expr(expr)
    {
    }

private:
    std::string m_id;
    Expr* m_expr;
};
}
