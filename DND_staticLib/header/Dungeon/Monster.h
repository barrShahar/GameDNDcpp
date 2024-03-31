#pragma once
#include "GameParams.h"
namespace experis
{
class Monster
{
public:
    explicit Monster(Number a_maxHealth, Number a_attackDmg);
    Monster(const Monster& a_other) = delete;
    Monster& operator=(const Monster& a_other) = delete;
    ~Monster() = default;

    Number DamageAndAttack(Number a_hitPoints);
    bool IsAlive() const;

    Number GetLifePoints() const;
private:
    Number m_lifePoints;
    Number m_attackDmg;
};
}  // namespace experis
