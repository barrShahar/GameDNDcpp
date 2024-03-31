#include "pch.h"
#include "Take.h"
#include "StringActionResponse.h"
#include <cassert>
#include <sstream>
#include<string>
namespace experis
{

std::unique_ptr<ActionResponse> Take::Act(Dungeon_mt &a_dungeon, Player& a_player) const
{
	//return std::make_unique<StringActionResponse>("You found a magic youth potion, +50 life");

	std::optional<Treasure> treasure = a_dungeon.GetTreasure(a_player.GetRoomNumber());
	if (treasure.has_value())
	{
		// TODO class and stategy design pattern
		//return std::make_unique<StringActionResponse>("You found magic ");
		std::string answer = "";
		switch (treasure.value())
		{
			case Treasure::MAGIC_YOUTH_POTION :
			{
				//return std::make_unique<StringActionResponse>("You found magic youth potion, your life point increase by 50");

				answer = "You found magic youth potion, your life point increase from ";
				answer += std::to_string(a_player.GetLife());
				answer += " points to ";
				a_player.SetLife(50 + a_player.GetLife());
				answer += std::to_string(a_player.GetLife());
				answer += " points.";
				break;
			}

			case Treasure::SWORD :
			{
				//return std::make_unique<StringActionResponse>("You found a sword! your attack points increase by 10");
				answer = "You found a sword! your attack points increase from "; 
				answer += std::to_string(a_player.GetAttack());
				answer += " to ";
				a_player.SetAttack(10 + a_player.GetAttack());
				answer += std::to_string(a_player.GetAttack());
				answer += " points!";
				break;
			}

			case Treasure::GUN:
			{
				answer = ("You found a gun!!! your attack points increase from ");
				answer += std::to_string(a_player.GetAttack());
				answer += " to ";
				a_player.SetAttack(50 + a_player.GetAttack());
				answer += std::to_string(a_player.GetAttack());
				answer += " points!";
				break;
			}

			default:
			{
				assert(!"Error in Take.cpp\n");
			}
		}
		std::unique_ptr<StringActionResponse> ans = std::make_unique<StringActionResponse>(answer);
		return ans;
	}

	return std::make_unique<StringActionResponse>("No treasure in this room");
}

} // experis