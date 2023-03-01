#pragma once

#include "id.h"
#include <string>

namespace ciparser {
class Message;
class Alias : public Id {
public:
    UnwrapResult unwrap(Set const&) override;
    std::string const& name() const override;
    std::string const& getLinkName() const
    {
        return linkName;
    }

    Alias(std::string_view name, std::string_view linkName);

private:
    std::string m_name;
    std::string linkName;
};
}
