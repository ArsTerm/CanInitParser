#include "message.h"

namespace ciparser {
Id::UnwrapResult Message::unwrap(Set const&) const
{
    return this;
}

std::string const& Message::name() const
{
    return m_name;
}
}
