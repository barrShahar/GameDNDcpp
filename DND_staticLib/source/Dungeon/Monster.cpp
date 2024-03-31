#include "pch.h"
#include "Monster.h"

experis::Monster::Monster(Number a_maxHealth, Number a_ttackDmg)
	: m_lifePoints { a_maxHealth }
	, m_attackDmg { a_ttackDmg }
{
	// Ctor
}

experis::Number experis::Monster::DamageAndAttack(Number a_hitPoints)
{

	m_lifePoints = (m_lifePoints < a_hitPoints) ? 0 : m_lifePoints - a_hitPoints;
	return (m_lifePoints == 0) ? 0 : m_attackDmg; // If dragon is dead he cannot attack back
}

bool experis::Monster::IsAlive() const
{
	return m_lifePoints > 0;
}

experis::Number experis::Monster::GetLifePoints() const
{
	return m_lifePoints;
}
