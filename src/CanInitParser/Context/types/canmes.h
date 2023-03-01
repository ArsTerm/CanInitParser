#pragma once

#include <cinttypes>
#include <vector>

namespace ciparser {
union CanMesData {
    uint8_t byte[8];
    uint16_t word[4];
    union {
        char b0 : 1;
        char b1 : 1;
        char b2 : 1;
        char b3 : 1;
        char b4 : 1;
        char b5 : 1;
        char b6 : 1;
        char b7 : 1;
    } bit[8];
};

using CanMes = CanMesData[256];

class ValueArray {
public:
    class Iterator {
    public:
        Iterator(std::pair<int, int> const* data)
        {
            if (data) {
                currTick = data->first;
                this->data = data + 1;
            }
        }
        friend Iterator const& operator++(Iterator& it)
        {
            it.currTick++;
            if (it.data->first < it.currTick) {
                it.data++;
            }
            return it;
        }

        friend int operator*(Iterator const& it)
        {
            return (it.data - 1)->second;
        }

        friend bool operator==(Iterator const& l, Iterator const& r)
        {
            return l.currTick == r.currTick && l.data == r.data;
        }

        friend bool operator!=(Iterator const& l, Iterator const& r)
        {
            return l.currTick != r.currTick || l.data != r.data;
        }

    private:
        int currTick;
        std::pair<int, int> const* data;
    };

    Iterator begin() const
    {
        return Iterator(data.data());
    }

    Iterator end() const
    {
        return Iterator(data.data() + data.size());
    }

    void push_back(std::pair<int, int> const& val)
    {
        data.push_back(val);
    }

    void emplace_back(int l, int r)
    {
        data.emplace_back(l, r);
    }

private:
    std::vector<std::pair<int, int>> data;
};
}
