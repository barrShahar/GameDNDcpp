#include "pch.h"
#include "Look.h"
#include "StringActionResponse.h"
namespace experis
{
std::unique_ptr<ActionResponse> experis::Look::Act(Dungeon_mt & a_dungeon, Player & a_player) const
{
    std::string names = a_dungeon.GetNames(a_player.GetRoomNumber());
    std::string life =  std::to_string(a_player.GetLife());
    std::string attackPoints = std::to_string(a_player.GetAttack());
    std::string status = "Life Points: " + life + "\nAttack Points: " + attackPoints;
    return std::make_unique<StringActionResponse>(names + status);
}
}
