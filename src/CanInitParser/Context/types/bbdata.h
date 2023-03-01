#pragma once

#include "canmes.h"
#include <cinttypes>

namespace ciparser {
struct BBTime {
    uint8_t hour = 0;
    uint8_t minutes = 0;
    uint8_t seconds = 0;
    uint8_t ticks = 0;

    BBTime() = default;
    BBTime(BBTime const&) = default;
    BBTime(BBTime const& base, int offset)
    {
        auto value = base.toTicks() + offset;
        hour = value / (60 * 24 * 128);
        value %= (60 * 24 * 128);
        minutes = value / (60 * 128);
        value %= (60 * 128);
        seconds = value / (128);
        value %= 128;
        ticks = value;
    }

    time_t toTicks() const
    {
        return ticks + (seconds * 128) + (minutes * 60 * 128)
                + (hour * 60 * 24 * 128);
    }

    friend bool operator>(BBTime const& l, BBTime const& r)
    {
        return l.toTicks() > r.toTicks();
    }

    friend bool operator>=(BBTime const& l, BBTime const& r)
    {
        return l.toTicks() >= r.toTicks();
    }

    friend bool operator<(BBTime const& l, BBTime const& r)
    {
        return l.toTicks() < r.toTicks();
    }

    friend bool operator<=(BBTime const& l, BBTime const& r)
    {
        return l.toTicks() <= r.toTicks();
    }

    friend bool operator==(BBTime const& l, BBTime const& r)
    {
        return l.toTicks() == r.toTicks();
    }

    friend bool operator!=(BBTime const& l, BBTime const& r)
    {
        return l.toTicks() != r.toTicks();
    }
};

#pragma pack(push, 1)
struct BBFrame {
    BBTime time;
    uint8_t id;
    CanMesData data;
    uint8_t reserved = 0;
    uint8_t timeSinceLast;
    uint8_t error;
};
#pragma pack(pop)
}
