#pragma once

#include "id.h"
#include <string>

namespace ciparser {
class Message;
class AliasMessage : public Id {
public:
    AliasMessage(std::string_view name, Message* m);
    UnwrapResult unwrap(Set const&) const override;
    std::string const& name() const override;

private:
    std::string m_name;
    Message* mess;
};
}
