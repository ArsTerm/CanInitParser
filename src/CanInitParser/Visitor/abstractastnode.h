#ifndef ABSTRACTASTNODE_H
#define ABSTRACTASTNODE_H

#include "value.h"
#include <string>
#include <vector>

namespace ciparser {
class AbstractASTNode {
public:
    AbstractASTNode();
    virtual ~AbstractASTNode() = default;

private:
    virtual std::vector<Value*> const& dependencies() const = 0;
};
}

#endif // ABSTRACTASTNODE_H
