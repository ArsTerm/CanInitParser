#include "value.h"
#include "../nodes/commentastnode.h"

namespace ciparser {
Id::UnwrapResult Value::unwrap(Set const&)
{
    return this;
}

std::string const& Value::name() const
{
    return m_id;
}

Value::Value(std::string_view id, Expr* expr, CommentAstNode* comment)
    : m_id(id), m_expr(expr)
{
    if (comment) {
        this->comment = comment->comment();
        this->attributes = comment->attributes();
    }
}

bool ciparser::Value::isSigned() const
{
    auto it = attributes.find("sign");
    if (it == attributes.end())
        return false;
    return it->second == "signed";
}
}
