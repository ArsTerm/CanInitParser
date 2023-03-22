#ifndef COMMENTASTNODE_H
#define COMMENTASTNODE_H

#include "astnode.h"
#include <optional>
#include <string>
#include <unordered_map>

namespace ciparser {
class CommentNode;

class CommentAstNode : public AstNode {
public:
    CommentAstNode(CommentNode* n);

    std::unordered_map<std::string, std::string> const& attributes() const
    {
        return m_attributes;
    }

    const std::string* attribute(std::string const& name) const;

    std::string const& comment() const
    {
        return m_comment;
    }

private:
    std::unordered_map<std::string, std::string> m_attributes;
    std::string m_comment;
};

}

#endif // COMMENTASTNODE_H
