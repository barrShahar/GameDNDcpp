#include "pch.h"
#include "ObserverPlayer.h"
namespace experis
{

experis::ObserverPlayer_mt::ObserverPlayer_mt(Player& a_player)
	: m_player { a_player }
	, m_notifyMutex {}
{
	// Ctor
}

Player& experis::ObserverPlayer_mt::GetPlayer()
{
	return m_player;
}

std::string experis::ObserverPlayer_mt::GetName() const
{
	return m_player.GetName();
}

void experis::ObserverPlayer_mt::Notify(const std::string& a_message)
{
	{	// gaurd
		std::lock_guard<std::mutex> lock(m_notifyMutex);
		m_player.NotifyPlayer(a_message);
	}
}

bool experis::ObserverPlayer_mt::IsEqual(const Player & a_player) const
{
	return &a_player == &m_player;
}

AttackPlayerResponse ObserverPlayer_mt::AttackPlayer(Number a_dmg)
{
	return m_player.AttackPlayer(a_dmg);
}

} // experis