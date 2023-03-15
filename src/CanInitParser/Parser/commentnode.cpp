#include "commentnode.h"
#include "../Visitor/caninitvisitor.h"
#include "../Visitor/nodes/commentastnode.h"

namespace ciparser {

CommentNode::CommentNode(
        std::unordered_map<std::string, std::string>&& attrs,
        std::string&& comment)
    : m_attributes(attrs), m_comment(comment)
{
}

AstNode* ciparser::CommentNode::accept(CanInitVisitor* visitor)
{
    return visitor->visitCommentNode(this);
}

std::string ciparser::CommentNode::toJson(int spaces)
{
    std::string result;
    fillString(result, spaces, "    ");
    result += "Comment {\n";
    spaces++;
    fillString(result, spaces, "    ");
    result += "attributes: [\n";
    spaces++;
    for (auto const& [name, val] : m_attributes) {
        fillString(result, spaces, "    ");
        result += "{\n";
        fillString(result, spaces + 1, "    ");
        result += "name: " + name + ",\n";
        fillString(result, spaces + 1, "    ");
        result += "value: " + val + "\n";
        fillString(result, spaces, "    ");
        result += "},\n";
    }
    spaces--;
    fillString(result, spaces, "    ");
    result += "]\n";
    fillString(result, spaces, "    ");
    result += "comment: \"" + m_comment + "\"\n";
    spaces--;
    fillString(result, spaces, "    ");
    result += '}';

    return result;
}

}
