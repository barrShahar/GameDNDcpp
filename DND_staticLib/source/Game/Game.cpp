#include "pch.h"
// Games includes
#include "Game.h"
#include "Player.h"
#include "GameExecuter.h"

//#include "Action.h"
//#include "Right.h"
//#include "Left.h"
//#include "Walk2.h"
//#include "PrintDirection.h"
//#include "Talk.h"
//#include "Shout.h"
//#include "Look.h"

#include "CoutWriter.h"
#include "NetWriter.h"


#include "CinReader.h"
#include "NetReader.h"

#include "SimpleNetMT.h"
#include "UrlPathReader.h"

namespace experis
{
experis::Game::Game()
	: m_net { 4010 }
	, m_dungeon {}
{
	// Ctor
}


void Game::ServerPlay()
{
	
	while (true)
	{
		simplenet::SimpleNetMT::Connection c = m_net.WaitForConnection();
		experis::NetWriter netWriter { c };
		experis::NetReader netReader { c };
		netWriter.Write("Welcome! Please enter player name\n");
		std::string userName = netReader.ReadLine();
		Player player { userName, netWriter };
		m_dungeon.RegisterPlayer(player);
		netWriter.Write("\nWelcome " + userName + "!\n");

		try
		{

			auto [path, isHttp] = simplenet::TryReadUrlPath(c);

			if (isHttp)  // Not supporting!!
			{

			}
			else
			{
				GameExecuter executer { netWriter, netReader, m_dungeon, player };

				executer.Execute();
			}
					
		}
		catch (const simplenet::SimpleNetMT::ConnectionClosed&)
		{
			// unregister player!
			m_dungeon.UnregisterPlayer(player, player.GetRoomNumber());
			std::cout << "CLOSED\n";
		}
	}
}

void Game::GeneralPlay(Writer& a_writer, Reader& a_reader)
{
#ifdef _DEBUG
	std::cout << "telnet 192.168.68.119 4010\n";
#endif // _DEBUG

	a_writer.Write("\nWelcome! Please enter player name\n");
	std::string userName = a_reader.ReadLine();
	Player player { userName, a_writer };
	m_dungeon.RegisterPlayer(player);
	a_writer.Write("Welcome " + userName + "!\n");

	GameExecuter executer { a_writer, a_reader, m_dungeon, player };

	executer.Execute();

}

void experis::Game::Play() 
{

	experis::CinReader cinReader(std::cin);
	experis::CoutWriter coutWrtier(std::cout);
	GeneralPlay(coutWrtier, cinReader);
}

/*
size_t Game::Walk(const size_t a_roomNum,const Direction a_direction) const
{
	return m_dungeon.Walk(a_roomNum, a_direction);
}
*/

} // experis