#pragma once
#include "Action.h"
namespace experis
{

class Right : public Action
{
public:
    explicit Right() = default;
    Right(const Right& a_other) = delete;
    Right& operator=(const Right& a_other) = delete;
    ~Right() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis