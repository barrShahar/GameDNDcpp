#pragma once
#include <string>
#include "GameParams.h"
#include "Writer.h"
#include <optional>
namespace experis
{

static constexpr Number STARTING_LIFE_POINTS = 100;
static constexpr Number STARTING_ATTACK_POINTS = 20;

class Player
{
public:
    explicit Player(const std::string& a_name, Writer& a_writer);
    Player(const Player& a_other) = delete;
    Player& operator=(const Player& a_other) = delete;
    ~Player() = default;

    void NotifyPlayer(const std::string& a_message);
    AttackPlayerResponse AttackPlayer(Number a_dmg);

    // Getters
    const std::string& GetName() const;
    const Number GetRoomNumber() const;
    const Direction GetDirection() const;
    const std::string& GetPlayerGameArgument() const;
    Number GetLife() const;
    Number GetAttack() const;
    bool IsAlive() const;

    // Setters
    void SetRoomNumber(Number a_number);
    void SetDirection(Direction a_direction);
    void SetPlayerGameArgument(const std::optional<std::string>& a_message);
    void SetLife(Number a_lifePoints);
    void SetAttack(Number a_attackPoints);

private:
    const std::string m_name;
    std::optional<std::string> m_messageToPass;
    Writer& m_writer;
    Number m_roomNum;
    Number m_life;
    Number m_attack;
    Direction m_direction;
};
}  // namespace experis
