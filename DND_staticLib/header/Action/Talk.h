#pragma once
#include "Action.h"

namespace experis
{
// Sends a messages to all players in the room
class Talk : public Action
{
public:
    explicit Talk() = default;
    Talk(const Talk& a_other) = delete;
    Talk& operator=(const Talk& a_other) = delete;
    ~Talk() = default;
    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt &a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis