#include "pch.h"
#include "Left.h"
#include <sstream>
#include "StringActionResponse.h"
namespace experis
{
std::unique_ptr<ActionResponse> experis::Left::Act(Dungeon_mt& a_dungeon, Player& a_player) const
{
    int currDirection = static_cast< int > (a_player.GetDirection());
    int size = static_cast< int > (Direction::SIZE);
    currDirection = (currDirection == 0) ? 3 : (currDirection - 1) % size;

    a_player.SetDirection(static_cast< Direction > (currDirection));

    std::stringstream reply;
    reply << "You are now facing " << DIRECTION_STRING[static_cast< Number >(a_player.GetDirection())];

    return std::make_unique<StringActionResponse>(reply.str());
}

} // experis