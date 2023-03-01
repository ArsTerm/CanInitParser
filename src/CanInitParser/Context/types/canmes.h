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
}
