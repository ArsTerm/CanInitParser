#include "aliasmessage.h"

namespace ciparser {
AliasMessage::AliasMessage(std::string_view name, Message* m)
    : m_name(name), mess(m)
{
}

Id::UnwrapResult AliasMessage::unwrap(Set const&)
{
    return mess;
}

const std::string& AliasMessage::name() const
{
    return m_name;
}

const Message* AliasMessage::message() const
{
    return mess;
}

}
