#pragma once
#include "Action.h"
namespace experis
{

class AttackDragon : public Action
{
public:
    explicit AttackDragon() = default;
    AttackDragon(const AttackDragon& a_other) = delete;
    AttackDragon& operator=(const AttackDragon& a_other) = delete;
    ~AttackDragon() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis