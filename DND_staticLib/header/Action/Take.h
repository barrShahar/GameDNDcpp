#pragma once
#include "Action.h"

namespace experis
{
// Sends a messages to all players in the room
class Take : public Action
{
public:
    explicit Take() = default;
    Take(const Take& a_other) = delete;
    Take& operator=(const Take& a_other) = delete;
    ~Take() = default;
    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt &a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis