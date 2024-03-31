#include "pch.h"
#include "GameExecuter.h"
#include <cassert>

#include"Right.h"
#include "Left.h"
#include "Walk.h"
#include "Talk.h"
#include "Shout.h"
#include "Look.h"
#include "Take.h"
#include "Attack.h"
#include "AttackDragon.h"
namespace experis
{
experis::GameExecuter::GameExecuter(Writer & a_writer,
									Reader & a_reader,
									Dungeon_mt & a_dungeon,
									Player & a_player)
	: m_writer { a_writer }
	, m_reader { a_reader }
	, m_dungeon { a_dungeon }
	, m_player { a_player }
	, m_currentState { STATE::INIT }
	, m_parser {}
	, m_commandState {}
	, m_actions {}
	, m_currCommand { std::nullopt }
	, m_statesFunctionPointers { 
		std::bind(&GameExecuter::StateInit, this),
		std::bind(&GameExecuter::WaitingForInput, this),
		std::bind(&GameExecuter::StringCommand, this),
		std::bind(&GameExecuter::GetUserInput, this),
		std::bind(&GameExecuter::Help, this),
		std::bind(&GameExecuter::AttackHandler, this) }
{
	// Ctor
	m_actions[COMMAND::left] = std::make_unique<Left>();
	m_actions[COMMAND::right] = std::make_unique<Right>();
	m_actions[COMMAND::walk] = std::make_unique<Walk>();
	m_actions[COMMAND::talk] = std::make_unique<Talk>();
	m_actions[COMMAND::shout] = std::make_unique<Shout>();
	m_actions[COMMAND::look] = std::make_unique<Look>();
	m_actions[COMMAND::take] = std::make_unique<Take>();
	m_actions[COMMAND::attack] = std::make_unique<Attack>();

	//m_actions["right"] = std::make_unique<Right>();
	//m_actions["walk"] = std::make_unique<Walk2>();
	//m_actions["shout"] = std::make_unique<Shout>();
	//m_actions["look"] = std::make_unique<Look>();
	m_commandState[COMMAND::left] = STATE::STRING_ACT;
	m_commandState[COMMAND::right] = STATE::STRING_ACT;
	m_commandState[COMMAND::walk] = STATE::STRING_ACT;
	m_commandState[COMMAND::talk] = STATE::GET_INPUT; 
	m_commandState[COMMAND::shout] = STATE::GET_INPUT;
	m_commandState[COMMAND::look] = STATE::STRING_ACT;
	m_commandState[COMMAND::take] = STATE::STRING_ACT;
	m_commandState[COMMAND::help] = STATE::HELP;
	m_commandState[COMMAND::attack] = STATE::ATTACK;
	m_commandState[COMMAND::quit] = STATE::EXIT;
}

void experis::GameExecuter::Execute()
{
	STATE currState = STATE::INIT;
	while (currState != STATE::EXIT)
	{
		// Call the function of the current state and updating currState;
		currState = m_statesFunctionPointers[static_cast< Number >(currState)]();
	}

	m_writer << "**End Game**\n";
}

// Draw the room and return nextState (WAITING_FOR_INPUT)
STATE experis::GameExecuter::StateInit()
{
	m_dungeon.DrawRoom(m_writer, 0, Direction::NORTH);
	return STATE::WAITING_FOR_INPUT;
}

// Parsing command from user and return new state if the command exist, otherwise
// return the same state;
STATE GameExecuter::WaitingForInput()
{
	std::string untrustedInput = m_reader.ReadLine();
	if (!m_player.IsAlive())
	{
		return STATE::EXIT;
	}
	m_currCommand = m_parser.ParseUserInput(untrustedInput);
	if (m_currCommand.has_value())
	{
		return m_commandState.at(m_currCommand.value());
	}
	return STATE::WAITING_FOR_INPUT;
}

STATE GameExecuter::StringCommand()
{
	assert(m_currCommand.has_value());
	// activate Action function the returns a poiner to ActionResponse Data 	
	std::unique_ptr<ActionResponse> respone = m_actions.at(m_currCommand.value()).get()->Act(m_dungeon, m_player);

	// reset current command
	m_currCommand = std::nullopt;

	m_dungeon.DrawRoom(m_writer, m_player.GetRoomNumber(), m_player.GetDirection());

	// Output the data
	if (respone)
	{
		m_writer.Write(respone.get()->GetResponse().first.get());
		m_writer.Write('\n');
	}

	return STATE::WAITING_FOR_INPUT;
}

STATE GameExecuter::GetUserInput()
{
	assert(m_currCommand.has_value());
	m_writer << "Insert input for " << COMMAND_STRING[static_cast< Number >(m_currCommand.value())] << " command:\n";
	std::string user_input = m_reader.ReadLine();
	m_player.SetPlayerGameArgument(std::make_optional(user_input));
	return STATE::STRING_ACT;
	m_actions.at(m_currCommand.value()).get()->Act(m_dungeon, m_player);
	m_currCommand = std::nullopt;

	m_player.SetPlayerGameArgument(std::nullopt); // clear arguemnt
	return STATE::WAITING_FOR_INPUT;
}

STATE GameExecuter::Help()
{
	for (int i = 0; i < static_cast<int>(COMMAND::SIZE); ++i)
	{
		m_writer << std::string { COMMAND_STRING[i] } << "\n";
	}
	return STATE::WAITING_FOR_INPUT;
}

STATE GameExecuter::AttackHandler()
{
	// Who do you want to attack?
	
	if (m_dungeon.IsMonsterInTheRoom(m_player.GetRoomNumber()))
	{
		m_player.SetPlayerGameArgument("dragon");
		return STATE::STRING_ACT;
	}

	// Assuming all the names are different
	std::string playersToAttack = m_dungeon.GetNames(m_player.GetRoomNumber());
	m_writer << "Who do you want to attack? options:\n";
	m_writer << playersToAttack << "\n";
	
	return STATE::GET_INPUT;
}
 


} // experis