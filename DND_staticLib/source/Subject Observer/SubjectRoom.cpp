#include "pch.h"
#include "SubjectRoom.h"

std::string experis::SubjectRoom_mt::GetNames() const
{
	std::lock_guard<std::mutex> lock(m_roomMutex);
	std::string playersNames = "Players Names:\n";
	for (const std::pair<std::string const, std::unique_ptr<ObserverPlayer_mt>>& player : m_observersMap)
	{
		playersNames.append(player.second.get()->GetName());
		playersNames.append("\n");
	}
	return playersNames;
}

void experis::SubjectRoom_mt::Register(Player& a_player)
{
	{	// gaurd
		std::lock_guard<std::mutex> lock(m_roomMutex);
		m_observersMap.insert(std::make_pair(a_player.GetName(), std::make_unique<ObserverPlayer_mt>(a_player)));
	}
}

void experis::SubjectRoom_mt::Unregister(Player& a_player)
{
	{	// gaurd
		std::lock_guard<std::mutex> lock(m_roomMutex);
		for (Map::iterator it = m_observersMap.begin();
			 it != m_observersMap.end(); ++it)
		{
			if ((*it).second.get()->IsEqual(a_player))
			{
				m_observersMap.erase(it);
				break;
			}
		}
	}
}

void experis::SubjectRoom_mt::NotifyAll(const std::string& a_message)
{
	std::pair< std::string, std::unique_ptr<ObserverPlayer_mt>> f;
	for (std::pair<std::string const, std::unique_ptr<ObserverPlayer_mt>>& pair : m_observersMap)
	{
		 pair.second.get()->Notify(a_message);
	}
}

experis::AttackPlayerResponse experis::SubjectRoom_mt::AttackPlayer(const std::string& a_playerToAttack, Number a_dmg)
{
	{	// gaurd
		std::lock_guard<std::mutex> lock(m_roomMutex);
		Map::iterator it = m_observersMap.find(a_playerToAttack);
		if (it != m_observersMap.end())
		{
			return  it->second.get()->AttackPlayer(a_dmg);
		}

		return AttackPlayerResponse(false);
	}
}
