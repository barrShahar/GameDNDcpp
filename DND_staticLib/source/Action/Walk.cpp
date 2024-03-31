#include "pch.h"
#include "Walk.h"
#include "StringActionResponse.h"
namespace experis
{
std::unique_ptr<ActionResponse> experis::Walk::Act(Dungeon_mt & a_dungeon, Player & a_player) const
{
    Number currentRoom = a_player.GetRoomNumber();
    Number nextRoom = a_dungeon.Walk_mt(currentRoom, a_player.GetDirection());
    if (nextRoom == THERE_IS_A_DRAGON)
    {
        return std::make_unique<StringActionResponse>("Can't pass the dragon!\n");
    }

    if (nextRoom != currentRoom)    // unregister and register player to differet room
    {
        a_dungeon.UnregisterPlayer(a_player, currentRoom);
        a_player.SetRoomNumber(nextRoom);
        a_dungeon.RegisterPlayer(a_player, nextRoom);
    }
    else
    {
        a_player.SetRoomNumber(nextRoom);
    }

     return std::unique_ptr<ActionResponse>();
}

} // experis