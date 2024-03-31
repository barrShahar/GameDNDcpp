#include "pch.h"
#include "AttackDragon.h"

namespace experis
{
std::unique_ptr<ActionResponse> experis::AttackDragon::Act(Dungeon_mt & a_dungeon, Player & a_player) const
{
    Number lifePointsBeforeAttack = a_player.GetLife();
    if (a_player.GetPlayerGameArgument() == "dragon")
    {
        // TODO: Attack dragon function in dungeon and in room
        // Get how much hp the dragon hit me with (the difference), and how much life points the dragon remain
        // Perhaps I can just print the player hp
    }
    return std::unique_ptr<ActionResponse>();
}

}