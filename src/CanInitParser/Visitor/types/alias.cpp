#include "alias.h"
#include "../nodes/commentastnode.h"
#include <cassert>

namespace ciparser {
Alias::Alias(
        std::string_view name, std::string_view link, CommentAstNode* comment)
    : m_name(name), linkName(link)
{
    if (comment) {
        this->comment = comment->comment();
        this->attribs = comment->attributes();
    }
}

Alias::UnwrapResult Alias::unwrap(Set const& set)
{
    auto link = set.find(linkName);
    assert(link != set.end());

    return link->second->unwrap(set);
}

std::string const& Alias::name() const
{
    return m_name;
}

bool Alias::isSigned() const
{
    auto it = attribs.find("sign");
    if (it == attribs.end())
        return false;
    return it->second == "signed";
}
}
