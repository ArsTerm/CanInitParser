#include "valuesarray.h"

namespace ciparser {

ValuesArray::ValuesArray()
{
    values[0] = 0;
}

void ValuesArray::insert(size_t position, int value)
{
    values[position] = value;
}

void ciparser::ValuesArray::reset()
{
    values.clear();
}

}
