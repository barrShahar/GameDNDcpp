#include "pch.h"
#include "Talk.h"

namespace experis
{
std::unique_ptr<ActionResponse> experis::Talk::Act(Dungeon_mt& a_dungeon, Player& a_player) const
{
    std::string message = a_player.GetName() + ": " + a_player.GetPlayerGameArgument();
    a_dungeon.NotifyRoom(a_player.GetRoomNumber(), message);

    a_player.SetPlayerGameArgument(std::nullopt);
    return std::unique_ptr<ActionResponse>();
}
}
