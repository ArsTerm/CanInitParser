#pragma once

namespace ciparser {
class Value {
public:
    enum Type { Int8, Uint8, Int16, Uint16, Bit, Index };

    Type type() const
    {
        return m_type;
    }

    int index1() const
    {
        if (type() != Index) {
            return m_index1;
        }
        return -1;
    }

    int index2() const
    {
        if (type() != Index) {
            return m_index2;
        }
        return -1;
    }

    int bit() const
    {
        if (type() == Bit) {
            return m_bit;
        }
        return -1;
    }

    int value() const
    {
        if (type() == Index) {
            return m_index1;
        }
        return -1;
    }

    static Value fromIndex(int value)
    {
        Value val;
        val.m_type = Index;
        val.m_index1 = value;
        return val;
    }

    static Value fromBit(int idx1, int idx2, int bit)
    {
        Value val;
        val.m_type = Bit;
        val.m_index1 = idx1;
        val.m_index2 = idx2;
        val.m_bit = bit;
        return val;
    }

    static Value fromInt(Type type, int idx1, int idx2)
    {
        Value val;
        val.m_type = type;
        val.m_index1 = idx1;
        val.m_index2 = idx2;
        return val;
    }

private:
    Value();

    Type m_type;
    int m_index1;
    int m_index2;
    int m_bit;
};
}
