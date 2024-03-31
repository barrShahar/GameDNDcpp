


// DND_MAIN_V02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
using namespace std::chrono_literals;
using ThreadContainer = std::vector<std::thread>;

static constexpr size_t MAX_USER_NUM = 4;

void NetServer(experis::Game& a_game)
{
	a_game.ServerPlay();
}
int main()
{
	experis::Game g;

	ThreadContainer threads;

	for (size_t i = 0; i < MAX_USER_NUM; ++i)
	{
		threads.push_back(std::thread { [&g]()
		{
			g.ServerPlay();
		} });
	}

	// g.Play();
#ifdef _DEBUG
	std::cout << "telnet 192.168.68.119 4010\n";
#endif // _DEBUG

	for (std::thread& t : threads)
	{
		//std::cout << "Waiting for other threads to die\n";
		t.join();
	}

	return 0;
}


