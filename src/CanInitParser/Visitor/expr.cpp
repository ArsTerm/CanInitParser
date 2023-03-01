#include "expr.h"
#include "types/value.h"

namespace ciparser {
std::optional<Id::UnwrapResult> BinaryExpr::linkId(Id::Set const& set)
{
    auto opt = l->linkId(set);
    if (opt.has_value()) {
        auto ret = opt.value();
        if (ret.index() == 0) {
            l = new MessExpr(std::get<0>(ret));
        } else if (ret.index() == 1) {
            auto val = std::get<1>(ret);
            l = val->expr();
            l->linkId(set);
        }
    }

    opt = r->linkId(set);
    if (opt.has_value()) {
        auto ret = opt.value();
        if (ret.index() == 0) {
            r = new MessExpr(std::get<0>(ret));
        } else if (ret.index() == 1) {
            auto val = std::get<1>(ret);
            r = val->expr();
            r->linkId(set);
        }
    }

    return std::nullopt;
}
}
