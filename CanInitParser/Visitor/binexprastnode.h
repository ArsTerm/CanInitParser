#ifndef BINEXPRASTNODE_H
#define BINEXPRASTNODE_H

#include "CanInitParser_global.h"
#include "abstractastnode.h"

namespace ciparser {
class BinExprASTNode : public AbstractASTNode {
    DISABLE_COPY(BinExprASTNode)
public:
    enum Operation { Sum, Sub, And, Or, Assign, Comparsion };

    BinExprASTNode(AbstractASTNode* lval, AbstractASTNode* rval, Operation op)
        : m_lvalue(lval), m_rvalue(rval), m_operation(op)
    {
    }

    Operation operation() const
    {
        return m_operation;
    }

    AbstractASTNode* lvalue() const
    {
        return m_lvalue;
    }

    AbstractASTNode* rvalue() const
    {
        return m_rvalue;
    }

private:
    AbstractASTNode* m_lvalue;
    AbstractASTNode* m_rvalue;
    Operation m_operation;
};
}

#endif // BINEXPRASTNODE_H
