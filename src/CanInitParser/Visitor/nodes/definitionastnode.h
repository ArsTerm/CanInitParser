#pragma once

#include "astnode.h"
#include "commentastnode.h"

namespace ciparser {
class DefinitionAstNode : public AstNode {
public:
    std::string const attribute(std::string const& name);

private:
    std::unordered_map<std::string, std::string> m_attribs;
};
}
