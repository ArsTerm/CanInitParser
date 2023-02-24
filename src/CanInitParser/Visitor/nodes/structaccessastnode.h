#pragma once

#include "astnode.h"
#include <string>

namespace ciparser {
class StructAccessAstNode : public AstNode {
public:
    StructAccessAstNode(AstNode* obj, std::string_view id)
        : m_object(obj), m_id(id)
    {
    }

    AstNode* object() const
    {
        return m_object;
    }

    std::string const& id() const
    {
        return m_id;
    }

private:
    AstNode* m_object;
    std::string m_id;
};
}
