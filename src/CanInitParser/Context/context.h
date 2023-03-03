#pragma once

#include "../CanInitParser_global.h"
#include "../Visitor/expr.h"
#include "types/bbdata.h"
#include <unordered_map>

namespace ciparser {
class ValueHandle {
public:
    ValueHandle() = default;

    ValueHandle(Expr* e) : expr(e)
    {
    }

    ValueHandle(int8_t* ptr) : ptr(ptr)
    {
    }

    bool isNull() const
    {
        return expr == nullptr;
    }

    int get() const
    {
        if (ptr)
            return *ptr;
        return expr->eval();
    }

    friend int operator*(ValueHandle const& val)
    {
        return val.get();
    }

private:
    Expr* expr = nullptr;
    int8_t* ptr = nullptr;
};

class CANINITPARSER_EXPORT Context {
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
            return ValueHandle();
        }
        return ValueHandle(it->second);
    }

    ValueHandle handle(int mes, int offset) const
    {
        return ValueHandle((int8_t*)&canMes[mes].byte[offset]);
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

    BBTime const& endTime() const
    {
        return (end - 1)->time;
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
