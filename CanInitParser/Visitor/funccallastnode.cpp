#include "funccallastnode.h"


namespace ciparser {
const std::string &FuncCallASTNode::name() const
{
    return m_name;
}

const std::vector<AbstractASTNode *> &FuncCallASTNode::params() const
{
    return m_params;
}

}
