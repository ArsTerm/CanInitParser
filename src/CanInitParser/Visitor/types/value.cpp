#include "value.h"

namespace ciparser {
Id::UnwrapResult Value::unwrap(Set const&)
{
    return this;
}

std::string const& Value::name() const
{
    return m_id;
}
}
