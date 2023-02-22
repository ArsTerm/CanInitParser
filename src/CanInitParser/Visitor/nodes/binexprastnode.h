#pragma once

#include "../expr.h"
#include "astnode.h"
#include <string>
#include <unordered_map>
#include <vector>

namespace ciparser {
class BinExprAstNode : public AstNode {
public:
    Expr* expr() const
    {
        return m_expr;
    }

    std::vector<std::string> const& dependencies() const
    {
        return m_dependencies;
    }

    BinExprAstNode(Expr* expr, std::vector<std::string>&& deps)
        : m_expr(expr), m_dependencies(deps)
    {
    }

private:
    Expr* m_expr;
    std::vector<std::string> m_dependencies;
};
}
