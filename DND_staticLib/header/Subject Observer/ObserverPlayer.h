#pragma once
#include "ObserverBase.h"
#include <memory>
#include <mutex>
namespace experis
{
class ObserverPlayer_mt : public ObserverBase
{
public:
    explicit ObserverPlayer_mt(Player& a_player);
    ObserverPlayer_mt(const ObserverPlayer_mt& a_other) = delete;
    ObserverPlayer_mt& operator=(const ObserverPlayer_mt& a_other) = delete;
    ~ObserverPlayer_mt() = default;

     Player& GetPlayer();
    std::string GetName() const;
    virtual void Notify(const std::string& a_message) override;
    bool IsEqual(const Player& a_player) const;
    AttackPlayerResponse AttackPlayer(Number a_dmg);

private:
    Player& m_player;
    std::mutex m_notifyMutex;
};
}  // namespace experis