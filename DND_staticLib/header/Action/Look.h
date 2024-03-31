#pragma once
#include "Action.h"
namespace experis
{

class Look : public Action
{
public:
    explicit Look() = default;
    Look(const Look& a_other) = delete;
    Look& operator=(const Look& a_other) = delete;
    ~Look() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis