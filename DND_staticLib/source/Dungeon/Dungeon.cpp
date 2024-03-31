#include "pch.h"
#include "Dungeon.h"
#include "GameParams.h"


#include <vector>
//#include <random>
//#include <queue>

namespace experis
{
experis::Dungeon_mt::Dungeon_mt()
	: m_dungeonGaurd {}
	, m_mtx {}
	, m_rooms { CreateDungeon() }
{
	// Ctor 
}

void Dungeon_mt::DrawRoom(Writer& a_writer, Number a_roomNum, Direction a_playerDirection)
{
	m_rooms.at(a_roomNum).DrawRoom(a_writer, a_playerDirection);
}

Number Dungeon_mt::Walk_mt(Number a_roomNumber, Direction a_direction)
{
	const Room& room = m_rooms[a_roomNumber];

	Number direction = static_cast< Number > (a_direction);

	// If the walk is a valid move, return the number of the next room. otherwise return the number of the current room
	if (room.isDoor(a_direction))
	{	
		if (a_direction == Direction::NORTH && room.IsDragon())
		{
			return THERE_IS_A_DRAGON;
		}
		// Getting alias to the new room number for readability
		const Number newRoomNumber = room.GetNextDoorRoomNumber(a_direction);

		// Notify other players that reside in newRoom
		// RoomMessage(newRoomNumber, a_name + " has entered the room\n");

		// Returns new room number
		return newRoomNumber;
	}
	return a_roomNumber;
}

void Dungeon_mt::NotifyRoom(Number a_roomNumber, const std::string& a_message)
{
	Room& room = m_rooms.at(a_roomNumber);
	room.NotifyAll(a_message);
}



bool Dungeon_mt::IsMonsterInTheRoom(Number a_roomNumber)
{
	return m_rooms.at(a_roomNumber).IsDragon();
}

std::string Dungeon_mt::GetNames(Number a_roomNumber) const
{
	const Room& room = m_rooms.at(a_roomNumber);
	std::string names = room.GetNames();
	return room.GetNames();
}

void Dungeon_mt::Shout(Number a_roomNumber, const std::string& a_message)
{
	Room& room = m_rooms.at(a_roomNumber);
	for (Wall& wall : room)
	{
		if (wall.IsDoor())
		{
			NotifyRoom(wall.GetNextRoomNumber(), a_message);
		}
	}
	NotifyRoom(a_roomNumber, a_message);
}

void Dungeon_mt::RegisterPlayer(Player& a_player, Number a_roomNumber)
{
	NotifyRoom(a_player.GetRoomNumber(), a_player.GetName() + " has entered the room!");
	m_rooms.at(a_roomNumber).Register(a_player);
}

void Dungeon_mt::UnregisterPlayer(Player& a_player, Number a_roomNumber)
{
	m_rooms.at(a_roomNumber).Unregister(a_player);
}

AttackPlayerResponse Dungeon_mt::AttackPlayer(Number a_roomNumber, 
											  const std::string& attackerName, 
											  const std::string& a_attackedName, 
											  Number a_dmg, Number a_attackLifePoints)
{
	// TODO: Find player through subject and attack him
	Room& room = m_rooms.at(a_roomNumber);
	AttackPlayerResponse info = room.AttackPlayer(a_attackedName, a_dmg);
	Number lifePoints = (a_attackLifePoints > info.GetDamageToThisPlayer()) ?
		a_attackLifePoints - info.GetDamageToThisPlayer() : NUMBER_ZERO;
	info.m_PlayerRemainingLife = lifePoints;
	if (info.m_isValid)
	{
		// notify other dudes
		std::string message = "\n" + attackerName + " inflicted " + std::to_string(a_dmg) + " to " + a_attackedName + "!\n";
		message += a_attackedName + " dealth " + std::to_string(info.GetDamageToThisPlayer()) + " back.\n";
		message += attackerName + " life remaining: " + std::to_string(lifePoints) + "\n";
		message += a_attackedName + " remaining life points: " + std::to_string(info.m_otherPlayerRemainingLife);
		NotifyRoom(a_roomNumber, message);
	}
	return info;
}

AttackDragonResponse Dungeon_mt::AttackDragon(Number a_roomNumber, Number a_dmg)
{
	Room& room = m_rooms.at(a_roomNumber);
	return room.AttackDragon(a_dmg);
}

std::optional<Treasure> Dungeon_mt::GetTreasure(Number a_roomNumber)
{
	return 	m_rooms.at(a_roomNumber).GetTreasure_mt();
}

const experis::Rooms Dungeon_mt::CreateDungeon() const
{
	using std::make_pair;
	// Hard coded dungeon
	Number roomNumber = 0;
	Rooms rooms // return value
	{
		Room { NUMBER_ZERO, make_pair(true,Number(1)),make_pair(false,-1), make_pair(false,-1), make_pair(true, Number(2)), false, true },
		Room { Number(1), make_pair(true,Number(3)),make_pair(true,Number(4)), make_pair(true,NUMBER_ZERO), make_pair(false, -1), false, false },
		Room { Number(2), make_pair(false,-1),make_pair(true,NUMBER_ZERO), make_pair(false,-1), make_pair(false, -1), true, true },
		Room { Number(3), make_pair(true,Number(7)),make_pair(true,Number(5)), make_pair(true,Number(1)), make_pair(false, -1), true, true },
		Room { Number(4), make_pair(true,Number(5)),make_pair(false,Number(-1)), make_pair(false,Number(-1)), make_pair(true, Number(1)), false, true },
		Room { Number(5), make_pair(true,Number(6)),make_pair(false,Number(-1)), make_pair(true,Number(4)), make_pair(true, Number(3)), false, false },
		Room { Number(6), make_pair(false,Number(-1)),make_pair(false,Number(-1)), make_pair(true,Number(5)), make_pair(true, Number(7)), false, false },
		Room { Number(8), make_pair(false,Number(-1)),make_pair(true,Number(6)), make_pair(true,Number(3)), make_pair(false, Number(-1)), true, true },
	};
	return rooms;
	/*
		std::queue<std::unique_ptr<Room>> unexploredRooms;
	Number roomNum = 0;
	// Create First room
	unexploredRooms.push(std::make_unique<Room>
	(
		roomNum, std::make_pair(true, ++roomNum), 
		std::make_pair(false, -1), 
		std::make_pair(false, -1), 
		std::make_pair(false, -1), 
		false, true
	)
	);

	while (!unexploredRooms.empty())
	{
		// Dequeue room
		std::unique_ptr<Room>& roomToExplore = unexploredRooms.front();

		// For every open door in room, create another room:
		for (Room::Iterator it = roomToExplore->begin(); it != roomToExplore->end(); ++it)
		{
			if ((*it).IsDoor())
			{
				unexploredRooms.push(CreateRoom(++roomNum));
			}
		}

		// push room to vector
		rooms.push_back(std::move(unexploredRooms.front()));
		unexploredRooms.pop();
	}

	return std::move(rooms);
	*/
}

Number AttackDragonResponse::GetDragonRemainingLifePoints()
{
	return m_dragonRemainingLife;
}

Number AttackDragonResponse::GetDamageToPlayer() const
{
	return m_damageToPlayer;
}

} // experis


/*
* 
std::pair<bool,Number> getRandomBool_mt(double a_probability, Number& a_num)
{
	bool isDoor = getRandomBool_mt(a_probability);
	return isDoor ? std::make_pair(isDoor, ++a_num) : std::make_pair(isDoor, Number(0));
}

std::unique_ptr<Room> CreateRoom(Number& a_roomNumber)
{
	std::array<std::pair<bool,Number>, 4> bools;
	std::generate(bools.begin(), bools.end(), [&] ()
				  {
					  return getRandomBool_mt(IS_DOOR_PROBABILITY, a_roomNumber);
				  });

	Room
	{
	a_roomNumber,
	bools.at(0),
	bools.at(1),
	bools.at(2),
	bools.at(3),
	getRandomBool_mt(IS_DRAGON_PROBABILITY),
	getRandomBool_mt(IS_TREASURE_PROBABILITY)
	};

	std::unique_ptr<Room> returnValue = std::make_unique<Room>(
		a_roomNumber,
		bools.at(0),
		bools.at(1),
		bools.at(2),
		bools.at(3),
		getRandomBool_mt(IS_DRAGON_PROBABILITY),
		getRandomBool_mt(IS_TREASURE_PROBABILITY));

	return std::move(returnValue);
}

// This function is thread safe since there is no shared memory between
// threads, each thread allocate is own variables each time.
// Also, this function called only once befor creating new threads
bool getRandomBool_mt(double a_probability)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution dist(a_probability);
	return dist(gen);
}
*/