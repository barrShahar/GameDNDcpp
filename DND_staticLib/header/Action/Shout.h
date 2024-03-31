#pragma once
#include "Action.h"

namespace experis
{
// Sends a messages to all players in the room
class Shout : public Action
{
public:
    explicit Shout() = default;
    Shout(const Shout& a_other) = delete;
    Shout& operator=(const Shout& a_other) = delete;
    ~Shout() = default;
    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt &a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis