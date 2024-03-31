#pragma once
#include "Player.h"
#include "Dungeon.h"
#include "Player.h"
#include "Reader.h"
#include "Writer.h"
#include "StatesActParams.h"
#include <vector>
#include <functional>
#include "UserParser.h"
#include <memory>
#include "Action.h"
#include "StringActionResponse.h"
namespace experis
{
// Responsibility: Layer between user interface and the game
using ActMap = std::unordered_map<COMMAND, std::unique_ptr<experis::Action>>;

class GameExecuter
{
public:
    explicit GameExecuter(Writer& a_writer, 
                          Reader& a_reader,
                          Dungeon_mt& a_dungeon,
                          Player& a_player);
    GameExecuter(const GameExecuter& a_other) = delete;
    GameExecuter& operator=(const GameExecuter& a_other) = delete;
    ~GameExecuter() = default;

    void Execute();
private:
    // states
    std::vector <std::function<STATE()>> m_statesFunctionPointers;
    STATE StateInit();
    STATE WaitingForInput();
    STATE StringCommand();
    STATE GetUserInput();
    STATE Help();
    STATE AttackHandler();
    Dungeon_mt& m_dungeon;
    Writer& m_writer;
    Reader& m_reader;
    Player& m_player;
    UserParser m_parser;

    STATE m_currentState;
    ActMap m_actions;
    std::optional<COMMAND> m_currCommand;
    std::unordered_map<COMMAND, STATE> m_commandState;

};
}  // namespace experis