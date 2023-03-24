#pragma once

#include "astnode.h"
#include "commentastnode.h"

namespace ciparser {
class DefinitionAstNode : public AstNode {
public:
    DefinitionAstNode(CommentAstNode* comment);
    std::string const& attribute(std::string const& name) const;
    std::string const& comment() const;

private:
    CommentAstNode* m_comment;
};
}
