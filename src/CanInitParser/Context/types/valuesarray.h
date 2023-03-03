#ifndef VALUESARRAY_H
#define VALUESARRAY_H

#include "../../CanInitParser_global.h"
#include <map>

#ifdef CANINITPARSER_LIBRARY
#define EXPORT Q_DECL_EXPORT
#else
#define EXPORT Q_DECL_IMPORT
#endif

namespace ciparser {
class EXPORT ValuesArray {
#undef EXPORT
public:
    ValuesArray();

    void insert(size_t position, int value);
    void reset();

    int operator[](size_t position) const
    {
        auto it = values.upper_bound(position);
        if (it == values.begin()) {
            return it->second;
        }
        it--;
        return it->second;
    }

private:
    std::map<size_t, int> values;
};
}

#endif // VALUESARRAY_H
