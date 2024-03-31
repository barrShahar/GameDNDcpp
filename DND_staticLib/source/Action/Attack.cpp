#include "pch.h"
#include "Attack.h"
#include "StringActionResponse.h"
namespace experis
{
std::unique_ptr<ActionResponse> experis::Attack::Act(Dungeon_mt& a_dungeon, Player & a_player) const
{
    Number lifePointsBeforeAttack = a_player.GetLife();
    if (a_player.GetPlayerGameArgument() == "dragon")
    {
        AttackDragonResponse respone = a_dungeon.AttackDragon(a_player.GetRoomNumber(), a_player.GetAttack());
        if (respone.GetDragonRemainingLifePoints() == 0)
        {
            return std::make_unique<StringActionResponse>("There is no Dragon in the room");
        }

        std::string messageToPlayer = "Dragon remaining life : " + std::to_string(respone.GetDragonRemainingLifePoints());
        messageToPlayer += "\nPlayer damage recevied: " + std::to_string(respone.GetDamageToPlayer());
        if (a_player.GetLife() > respone.m_damageToPlayer)
        {
            a_player.SetLife(a_player.GetLife() - respone.m_damageToPlayer);

        }
        else
        {
            a_player.SetLife(0);
        }
        messageToPlayer += "\nLife remains: " + std::to_string(a_player.GetLife());
        
        return std::make_unique<StringActionResponse>(messageToPlayer);
    }
    AttackPlayerResponse respone =  a_dungeon.AttackPlayer(a_player.GetRoomNumber(), a_player.GetName(), a_player.GetPlayerGameArgument(), a_player.GetAttack(), a_player.GetLife());
    if (respone.m_isValid)
    {
        std::string answer = "You've dealth " + std::to_string(a_player.GetAttack()) + " damage!\n";
        answer += "You've recived " + std::to_string(respone.GetDamageToThisPlayer()) + " back!\n";
        a_player.SetLife(respone.m_PlayerRemainingLife);
        answer += "You're remaining life Points: " + std::to_string(a_player.GetLife());

        return std::make_unique<StringActionResponse>(answer);
        // return std::make_unique<StringActionResponse>();

    }
    return std::make_unique<StringActionResponse>("No " + a_player.GetPlayerGameArgument() + " currently in the room.");
}
}
