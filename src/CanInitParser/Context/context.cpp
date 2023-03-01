#include "context.h"
#include "../Visitor/types/message.h"
#include "../Visitor/types/value.h"

#include <iostream>

namespace ciparser {

Context::Context(BBFrame* data, size_t dataSize, Id::Set const& ids_vals)
    : m_data(data), dataSize(dataSize)
{
    end = m_data + dataSize;
    m_beginTime = m_data->time;

    for (auto& val : ids_vals) {
        auto result = val.second->unwrap(ids_vals);
        if (result.index() == 0) {
            auto mess = std::get<0>(result);
            linkMessage(mess);
            ids.emplace(val.first, new MessExpr(mess));
        } else if (result.index() == 1) {
            auto value = std::get<1>(result);
            if (auto bin = dynamic_cast<BinaryExpr*>(value->expr())) {
                linkMessage(bin);
            }
            ids.emplace(val.first, value->expr());
        } else {
            assert(false);
        }
    }

    updateUntil(m_beginTime);

    currentTick = m_data->time.toTicks();

    for (auto& id : ids) {
        std::cout << "Id: " << id.first
                  << ", value: " << typeid(*id.second).name() << '\n';
    }
}

bool Context::decTick()
{
    if (currentTick == 0) {
        return false;
    }
    if (m_data == end - dataSize) {
        currentTick--;
        return false;
    }
    auto nextTicks = (m_data - 1)->time.toTicks() - m_beginTime.toTicks();
    if (--currentTick == nextTicks) {
        return bbBack();
    }
    return false;
}

bool Context::incTick()
{
    if (m_data + 1 == end) {
        currentTick++;
        return false;
    }
    auto nextTicks = (m_data + 1)->time.toTicks() - m_beginTime.toTicks();
    if (++currentTick == nextTicks) {
        return bbStep();
    }
    return false;
}

bool Context::bbStep()
{
    if ((m_data + 1) == end) {
        return false;
    }
    m_data += 1;
    updateBB();
    return true;
}

bool Context::bbBack()
{
    if (m_data == end - dataSize) {
        return false;
    }
    m_data -= 1;
    updateBB();
    return true;
}

void Context::linkMessage(Message* m)
{
    switch (m->type()) {
    case Message::Int16:
    case Message::Uint16: {
        auto messId = m->messId();
        auto byte = m->offset();
        assert(messId < 255 && byte < 4);
        m->setData(&canMes[messId].word[byte]);
        break;
    }
    case Message::Int8:
    case Message::Uint8: {
        auto messId = m->messId();
        auto byte = m->offset();
        assert(messId < 255 && byte < 8);
        m->setData(&canMes[messId].byte[byte]);
        break;
    }
    case Message::Bit: {
        auto messId = m->messId();
        auto byte = m->offset();
        auto bit = m->bit();
        assert(messId < 255 && byte < 8 && bit < 8);
        m->setData(&canMes[messId].byte[byte]);
        break;
    }
    }
}

void Context::linkMessage(BinaryExpr* m)
{
    if (auto mess = dynamic_cast<MessExpr*>(m->left())) {
        linkMessage(mess->message());
    } else if (auto bin = dynamic_cast<BinaryExpr*>(m->left())) {
        linkMessage(bin);
    }

    if (auto mess = dynamic_cast<MessExpr*>(m->rigth())) {
        linkMessage(mess->message());
    } else if (auto bin = dynamic_cast<BinaryExpr*>(m->rigth())) {
        linkMessage(bin);
    }
}

void Context::updateUntil(const BBTime& time)
{
    while (m_data->time <= time) {
        if (!bbStep()) {
            return;
        }
    }
    m_data = (m_data);
}

void Context::updateBB()
{
    memcpy(&canMes[m_data->id].byte, m_data->data.byte, 8);
}

}
