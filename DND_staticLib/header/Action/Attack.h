#pragma once
#include "Action.h"
namespace experis
{

class Attack : public Action
{
public:
    explicit Attack() = default;
    Attack(const Attack& a_other) = delete;
    Attack& operator=(const Attack& a_other) = delete;
    ~Attack() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis