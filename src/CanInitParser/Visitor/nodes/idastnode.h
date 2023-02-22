#pragma once

#include "astnode.h"
#include <string>

namespace ciparser {
class IdAstNode : public AstNode {
public:
    IdAstNode(std::string const& name) : m_name(name)
    {
    }

    std::string const& name() const
    {
        return m_name;
    }

    std::string&& getName()
    {
        return std::move(m_name);
    }

private:
    std::string m_name;
};
}
