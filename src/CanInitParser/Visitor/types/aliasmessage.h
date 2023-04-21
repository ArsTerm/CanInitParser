#pragma once

#include "../../CanInitParser_global.h"
#include "id.h"
#include <string>

namespace cicompiler {
class Compiler;
}

namespace ciparser {
class Message;
class CANINITPARSER_EXPORT AliasMessage : public Id {
    friend class cicompiler::Compiler;

public:
    AliasMessage(std::string_view name, Message* m);
    UnwrapResult unwrap(Set const&) override;
    std::string const& name() const override;
    const Message* message() const;

private:
    std::string m_name;
    Message* mess;
};
}
