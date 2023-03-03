#include "valuesarray.h"

namespace ciparser {

ValuesArray::ValuesArray()
{
    values[0] = 0;
}

// to-do optimize
void ValuesArray::insert(size_t position, int value)
{
    if (!values.empty()) {
        auto it = values.end();
        it--;
        if (it->second == value && position >= it->first) {
            return;
        }
    }
    values[position] = value;
}

void ciparser::ValuesArray::reset()
{
    values.clear();
}

}
