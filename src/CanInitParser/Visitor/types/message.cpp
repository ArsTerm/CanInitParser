#include "message.h"

namespace ciparser {
Id::UnwrapResult Message::unwrap(Set const&)
{
    return this;
}

std::string const& Message::name() const
{
    return m_name;
}

bool Message::isSigned() const
{
    return m_type == Int8 || m_type == Int16;
}
}
