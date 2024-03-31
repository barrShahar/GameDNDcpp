#include "pch.h"
#include "Player.h"
#include <cassert>
#include <string>
#include <ostream>
namespace experis
{
experis::Player::Player(const std::string& a_name,Writer& a_writer)
	: m_name { a_name }
	, m_roomNum { 0 }
	, m_direction { Direction::NORTH }
	, m_writer { a_writer }
	, m_life { STARTING_LIFE_POINTS }
	, m_attack { STARTING_ATTACK_POINTS }
	, m_messageToPass { std::nullopt }
{
	// Ctor
}

void Player::NotifyPlayer(const std::string& a_message)
{

		m_writer << a_message << "\n";

}

AttackPlayerResponse Player::AttackPlayer(Number a_dmg)
{
	AttackPlayerResponse info(true);
	m_life = (m_life > a_dmg) ? m_life - a_dmg : 0;
	info.m_otherPlayerRemainingLife = m_life;
	info.m_DamageToPlayer = m_attack;
	info.m_isAttackedPlayerAlive = (m_life != 0);
	return info;
}

const std::string& experis::Player::GetName() const
{
	return m_name;
}

const Number experis::Player::GetRoomNumber() const
{
	return m_roomNum;
}

const Direction Player::GetDirection() const
{
	return m_direction;
}

const std::string& Player::GetPlayerGameArgument() const
{
	assert(m_messageToPass.has_value());
	return m_messageToPass.value();
}

Number Player::GetLife() const
{
	return m_life;
}

Number Player::GetAttack() const
{
	return m_attack;
}

bool Player::IsAlive() const
{
	return m_life != 0;
}

void Player::SetRoomNumber(Number a_number)
{
	m_roomNum = a_number;
}

void Player::SetDirection(Direction a_direction)
{
	m_direction = a_direction;
}

void Player::SetPlayerGameArgument(const std::optional<std::string>& a_message)
{
	m_messageToPass = a_message;
}

void Player::SetLife(Number a_lifePoints)
{
	 m_life = a_lifePoints;
}

void Player::SetAttack(Number a_attackPoints)
{
	m_attack = a_attackPoints;
}

} // experis