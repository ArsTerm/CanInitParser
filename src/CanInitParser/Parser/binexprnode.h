#ifndef BINEXPRNODE_H
#define BINEXPRNODE_H

#include "parsenode.h"

namespace ciparser {
class ExpressionNode;
class BinExprNode : public ParseNode {
public:
    enum Operation {
        Sum = TType::Plus,
        Sub = TType::Minus,
        Div = TType::LSlash,
        Mul = TType::Asterisk,
        Mod = TType::Percent,
        AndL = TType::AndLogic,
        OrL = TType::OrLogic,
        And = TType::And,
        Or = TType::Or,
        Xor = TType::Xor,
        Less = TType::LTriangle,
        LessOrEq = TType::LessOrEq,
        More = TType::RTriangle,
        MoreOrEq = TType::MoreOrEq,
        Eq = TType::Equal,
        Neq = TType::NotEqual,
        Assign = TType::Assign
    };
    BinExprNode() = delete;
    BinExprNode(BinExprNode const&) = delete;
    BinExprNode& operator=(BinExprNode const&) = delete;

    BinExprNode(ParseNode* l, ParseNode* r, Operation op)
        : m_l(l), m_r(r), m_op(op)
    {
    }

    BinExprNode(ParseNode* l, ParseNode* r, Token const& op)
        : m_l(l), m_r(r), m_op((Operation)op.type)
    {
    }

    ParseNode* l() const
    {
        return m_l;
    }

    ParseNode* r() const
    {
        return m_r;
    }

    Operation operation() const
    {
        return m_op;
    }

private:
    ParseNode* m_l;
    ParseNode* m_r;
    Operation m_op;

    // ParseNode interface
public:
    AbstractASTNode* accept(CanInitVisitor*) override;
    std::string toJson(int spaces) override;
};
}

#endif // BINEXPRNODE_H
