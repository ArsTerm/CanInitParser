#pragma once

#include "../CanInitParser_global.h"
#include "../Visitor/expr.h"
#include "types/bbdata.h"
#include "types/valuesarray.h"
#include <unordered_map>

namespace ciparser {
class ValueHandle {
public:
    ValueHandle(Expr* e) : expr(e)
    {
    }

    bool isNull() const
    {
        return expr == nullptr;
    }

    int get() const
    {
        return expr->eval();
    }

    friend int operator*(ValueHandle const& val)
    {
        return val.get();
    }

private:
    Expr* expr;
};

#ifdef CANINITPARSER_LIBRARY
#define EXPORT Q_DECL_EXPORT
#else
#define EXPORT Q_DECL_IMPORT
#endif

class EXPORT Context {
#undef EXPORT
public:
    Context();
    Context(BBFrame* data, size_t dataSize, Id::Set const& ids);

    int value(std::string const& name) const
    {
        auto it = ids.find(name);
        if (it == ids.end())
            assert(false);
        return it->second->eval();
    }

    ValueHandle handle(std::string const& name) const
    {
        auto it = ids.find(name);
        if (it == ids.end()) {
            return ValueHandle(nullptr);
        }
        return ValueHandle(it->second);
    }

    size_t position() const
    {
        return currentTick;
    }

    bool incTick();
    void reset();

    void setData(BBFrame* data, size_t dataSize);

    BBTime const& beginTime() const
    {
        return m_beginTime;
    }

private:
    BBFrame* m_data;
    BBFrame* end;
    size_t dataSize;
    size_t currentTick = 0;
    BBTime m_beginTime;
    std::unordered_map<std::string, Expr*> ids;
    CanMes canMes = {};

    void linkMessage(Message* m);
    void linkMessage(BinaryExpr* m);
    void updateUntil(BBTime const& time);
    void updateBB();
    bool bbStep();
};
}
