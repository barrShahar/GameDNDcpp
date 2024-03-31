#include "pch.h"
#include "Wall.h"
#include <cassert>

namespace experis
{
Wall::Wall(bool a_isDoor, Number a_nextRoomNumber)
    : m_isDoor { a_isDoor }
    , m_nextRoomNumber { a_nextRoomNumber }
{
    // Ctor
}

Wall::Wall(const Wall & a_other)
    : m_isDoor { a_other.m_isDoor }
    , m_nextRoomNumber { a_other.m_nextRoomNumber }
{
    // Copy ctor
}

const bool Wall::IsDoor() const
{
    return m_isDoor;
}
const Number Wall::GetNextRoomNumber() const
{
    assert(IsDoor());
    return m_nextRoomNumber;
}
} // experis
