#ifndef COMMENTNODE_H
#define COMMENTNODE_H

#include "parsenode.h"
#include <unordered_map>

namespace ciparser {

class CommentNode : public ParseNode {
    friend class CommentAstNode;

public:
    CommentNode(
            std::unordered_map<std::string, std::string>&& attrs,
            std::string&& comment);

    std::unordered_map<std::string, std::string> const& attributes() const
    {
        return m_attributes;
    }

    std::string const& comment() const
    {
        return m_comment;
    }

private:
    std::unordered_map<std::string, std::string> m_attributes;
    std::string m_comment;

    // ParseNode interface
public:
    AstNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};

}

#endif // COMMENTNODE_H
