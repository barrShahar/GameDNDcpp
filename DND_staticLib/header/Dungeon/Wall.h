#pragma once
#include "GameParams.h"
namespace experis
{
// One of 4 walls of Room.h class
class Wall
{
public:
    explicit Wall(bool a_isDoor, Number a_nextRoomNumber);
    Wall(const Wall& a_other);
    Wall& operator=(const Wall& a_other) = delete;
    ~Wall() = default;

    const bool IsDoor() const;
    const Number GetNextRoomNumber() const;

private:
    bool m_isDoor;
    Number m_nextRoomNumber;
};
}  // namespace experis