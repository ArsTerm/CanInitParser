#pragma once

#include "../expr.h"
#include "astnode.h"

namespace ciparser {
class IndexAccessAstNode : public AstNode {
public:
    IndexAccessAstNode(AstNode* object, Expr* index)
        : m_object(object), m_index(index)
    {
    }

    AstNode* object() const
    {
        return m_object;
    }

    Expr* index() const
    {
        return m_index;
    }

private:
    AstNode* m_object;
    Expr* m_index;
};
}
