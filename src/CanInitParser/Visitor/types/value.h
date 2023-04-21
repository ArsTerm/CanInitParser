#pragma once

#include "../../CanInitParser_global.h"
#include "id.h"
#include <string>
#include <vector>

namespace cicompiler {
class Compiler;
}

namespace ciparser {
class Message;
class Expr;
class CommentAstNode;

class CANINITPARSER_EXPORT Value : public Id {
    friend class cicompiler::Compiler;

public:
    std::string const& id() const
    {
        return m_id;
    }

    Expr* expr() const
    {
        return m_expr;
    }

    Expr* moveExpr();

    UnwrapResult unwrap(Set const&) override;
    std::string const& name() const override;
    bool isSigned() const override;

    Value(std::string_view id, Expr* expr, CommentAstNode* comment);
    ~Value() override;

private:
    std::string m_id;
    std::string comment;
    std::unordered_map<std::string, std::string> attributes;
    Expr* m_expr;
};
}
