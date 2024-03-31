#include "pch.h"
#include "Shout.h"

namespace experis
{
std::unique_ptr<ActionResponse> experis::Shout::Act(Dungeon_mt& a_dungeon, Player& a_player) const
{
    a_dungeon.Shout(a_player.GetRoomNumber(), a_player.GetPlayerGameArgument());

    a_player.SetPlayerGameArgument(std::nullopt);

    return std::unique_ptr<ActionResponse>();
}
}

