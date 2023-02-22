#pragma once

#include "id.h"
#include <string>

namespace ciparser {
class Message : public Id {
public:
    enum Type { Int8, Uint8, Int16, Uint16, Bit };

    Type type() const
    {
        return m_type;
    }

    int messId() const
    {
        return m_messId;
    }

    int offset() const
    {
        return m_offset;
    }

    int bit() const
    {
        return m_bit;
    }

    static Message bitMessage(int messId, int offset, int bit)
    {
        Message mess;
        mess.m_type = Bit;
        mess.m_messId = messId;
        mess.m_offset = offset;
        mess.m_bit = bit;
        return mess;
    }

    static Message intMessage(Type type, int messId, int offset)
    {
        Message mess;
        mess.m_type = type;
        mess.m_messId = messId;
        mess.m_offset = offset;
        return mess;
    }

    static size_t hash(Message const& m)
    {
        if (m.m_type != Bit)
            return std::hash<int>{}(m.m_type)
                    ^ std::hash<int>{}(m.m_messId << 1)
                    ^ std::hash<int>{}(m.m_offset << 2);

        return std::hash<int>{}(m.m_messId) ^ std::hash<int>{}(m.m_offset << 1)
                ^ std::hash<int>{}(m.m_bit << 2);
    }

    static bool equal(Message const& l, Message const& r)
    {
        if (l.m_type != r.m_type)
            return false;
        if (l.m_type != Bit)
            return l.m_messId == r.m_messId && l.m_offset == r.m_offset;

        return l.m_messId == r.m_messId && l.m_offset == r.m_offset
                && l.m_bit == r.m_bit;
    }

    void setData(void* data)
    {
        m_data = data;
    }

    template <class T>
    T value() const
    {
        return *((T*)m_data);
    }

    int bitValue() const
    {
        return (*((uint8_t*)m_data) >> m_bit) & 1;
    }

    UnwrapResult unwrap(Set const&) const override;
    std::string const& name() const override;

    Message() = default;

private:
    Type m_type;
    int m_messId;
    int m_offset;
    int m_bit;
    void* m_data;
    std::string m_name;
};
}

template <>
struct std::hash<ciparser::Message> {
    std::size_t operator()(ciparser::Message const& m) const
    {
        return ciparser::Message::hash(m);
    }
};

template <>
struct std::equal_to<ciparser::Message> {
    bool
    operator()(ciparser::Message const& l, ciparser::Message const& r) const
    {
        return ciparser::Message::equal(l, r);
    }
};
