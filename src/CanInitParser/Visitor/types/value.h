#pragma once

#include "id.h"
#include <string>
#include <vector>

namespace ciparser {
class Message;
class Expr;
class CommentAstNode;

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

    UnwrapResult unwrap(Set const&) override;
    std::string const& name() const override;
    bool isSigned() const override;

    Value(std::string_view id, Expr* expr, CommentAstNode* comment);

private:
    std::string m_id;
    std::string comment;
    std::unordered_map<std::string, std::string> attributes;
    Expr* m_expr;
};
}
