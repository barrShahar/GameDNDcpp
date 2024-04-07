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

    Dungeon_mt m_dungeon;
    simplenet::SimpleNetMT m_net;


};
}  // namespace experis
