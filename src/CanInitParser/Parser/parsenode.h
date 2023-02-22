#ifndef PARSENODE_H
#define PARSENODE_H

#include "../CanInitParser_global.h"
#include "../caninitlexer.h"
#include <vector>

namespace ciparser {
class CanInitVisitor;
class AstNode;
class CANINITPARSER_EXPORT ParseNode {
public:
    using Token = CanInitLexer::Token;
    using TType = CanInitLexer::TokenType;

    ParseNode();

    virtual AstNode* accept(CanInitVisitor*) = 0;
    virtual std::string toJson(int spaces = 0) = 0;

    virtual ~ParseNode() = default;

protected:
    void fillString(std::string& s, int spaces, char const* fill)
    {
        for (int i = 0; i < spaces; i++) {
            s += fill;
        }
    }
};
}
#endif // PARSENODE_H
