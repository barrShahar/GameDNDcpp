#pragma once
#include <memory>
#include "Player.h"
#include "ActionResponse.h"
#include "Dungeon.h"

namespace experis
{
class Action
{
public:
    explicit Action() = default;
    Action(const Action& a_other) = delete;
    Action& operator=(const Action& a_other) = delete;
    virtual ~Action() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const = 0;

private:

};
}  // namespace experis
