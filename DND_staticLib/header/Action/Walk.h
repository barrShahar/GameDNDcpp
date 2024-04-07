#pragma once
#include "Action.h"
namespace experis
{
class Walk : public Action
{
public:
    explicit Walk() = default;
    Walk(const Walk& a_other) = delete;
    Walk& operator=(const Walk& a_other) = delete;
    ~Walk() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis
