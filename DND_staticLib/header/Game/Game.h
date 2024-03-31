#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>
#include <tuple>
#include <cassert>
#include "SimpleNetMT.h"

#include "Writer.h"
#include "Reader.h"
#include "Dungeon.h"

namespace experis
{

class Game
{
    // Responsibility: initializing the game

public:
    explicit Game();
    Game(const Game& a_other) = delete;
    Game& operator=(const Game& a_other) = delete;
    ~Game() = default;


    
    void Play();
    void ServerPlay();
    void GeneralPlay(Writer& a_write, Reader& a_read);
    
private:

    // size_t Walk(const size_t a_roomNum, const Direction a_direction) const;
    //void DrawRoom(Writer & a_writer, const Player& a_player);
    Dungeon_mt m_dungeon;
    simplenet::SimpleNetMT m_net;


    // std::unordered_map<std::string, std::unique_ptr<Action>> m_afterActions;
};
}  // namespace experis