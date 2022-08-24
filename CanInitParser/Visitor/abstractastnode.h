#ifndef ABSTRACTASTNODE_H
#define ABSTRACTASTNODE_H

#include "CanInitParser_global.h"

namespace ciparser {
class CANINITPARSER_EXPORT AbstractASTNode {
public:
    virtual ~AbstractASTNode() = default;

protected:
    AbstractASTNode() = default;
};
}

#endif // ABSTRACTASTNODE_H
