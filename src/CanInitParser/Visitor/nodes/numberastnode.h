#pragma once

#include "astnode.h"

namespace ciparser {
class NumberAstNode : public AstNode {
public:
    NumberAstNode(int val) : m_value(val)
    {
    }

    int value() const
    {
        return m_value;
    }

private:
    int m_value;
};
}
