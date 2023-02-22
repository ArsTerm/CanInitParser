#include "expr.h"
#include "types/value.h"

namespace ciparser {
Id::UnwrapResult BinaryExpr::linkId(Id::Set const& set)
{
    auto ret = l->linkId(set);
    if (ret.index() == 0) {
        l = new MessExpr(std::get<0>(ret));
    } else if (ret.index() == 1) {
        auto val = std::get<1>(ret);
        l = val->expr();
        l->linkId(set);
    }

    ret = r->linkId(set);
    if (ret.index() == 0) {
        r = new MessExpr(std::get<0>(ret));
    } else if (ret.index() == 1) {
        auto val = std::get<1>(ret);
        r = val->expr();
        r->linkId(set);
    }

    return Id::UnwrapResult();
}
}
