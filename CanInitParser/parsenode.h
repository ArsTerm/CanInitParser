#ifndef PARSENODE_H
#define PARSENODE_H

#include "CanInitParser_global.h"
#include <caninitlexer.h>
#include <vector>

namespace ciparser {
class CanInitVisitor;
class AbstractASTNode;
class CANINITPARSER_EXPORT ParseNode {
public:
    using Token = CanInitLexer::Token;

    virtual AbstractASTNode* accept(CanInitVisitor*) = 0;

    virtual ~ParseNode() = default;

protected:
    ParseNode();
};
}
#endif // PARSENODE_H
