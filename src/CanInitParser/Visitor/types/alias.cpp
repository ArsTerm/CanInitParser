#include "alias.h"
#include <cassert>

namespace ciparser {
Alias::Alias(std::string_view name, std::string_view link)
    : m_name(name), linkName(link)
{
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
}
