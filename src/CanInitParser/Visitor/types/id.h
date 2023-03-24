#pragma once

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace ciparser {
class Message;
class Value;
class Id {
public:
    using Set = std::unordered_map<std::string, Id*>;
    using UnwrapResult = std::variant<Message*, Value*>;
    virtual UnwrapResult unwrap(Set const& names) = 0;
    virtual std::string const& name() const = 0;
    virtual bool isSigned() const = 0;

    virtual ~Id() = default;

private:
};
}

template <>
struct std::hash<ciparser::Id*> {
    size_t operator()(ciparser::Id* id)
    {
        return std::hash<std::string>{}(id->name());
    }
};

template <>
struct std::equal_to<ciparser::Id*> {
    bool operator()(ciparser::Id* l, ciparser::Id* r)
    {
        return l->name() == r->name();
    }
};
