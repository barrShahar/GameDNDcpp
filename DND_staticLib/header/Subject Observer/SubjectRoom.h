#pragma once
#include "SubjectBase.h"
#include "ObserverPlayer.h"
#include "SubjectBase.h"
#include <vector>
#include <memory>
#include <mutex>
#include <unordered_map>
namespace experis
{
class SubjectRoom_mt : public SubjectBase
{
    using Map = std::unordered_map<std::string, std::unique_ptr<ObserverPlayer_mt>>;
public:
    explicit SubjectRoom_mt() = default;
    SubjectRoom_mt(const SubjectRoom_mt& a_other) = delete;
    SubjectRoom_mt& operator=(const SubjectRoom_mt& a_other) = delete;
    ~SubjectRoom_mt() = default;

    std::string GetNames() const;

    virtual void Register(Player& a_player) override;
    virtual void Unregister(Player& a_player) override;

    virtual void NotifyAll(const std::string& a_message) override;
    AttackPlayerResponse AttackPlayer(const std::string& a_playerToAttack, Number a_dmg);
private:
    Map m_observersMap;
    mutable std::mutex m_roomMutex;
};
}  // namespace experis
