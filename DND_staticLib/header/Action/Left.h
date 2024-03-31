#pragma once
#include "Action.h"
namespace experis
{

class Left : public Action
{
public:
    explicit Left() = default;
    Left(const Left& a_other) = delete;
    Left& operator=(const Left& a_other) = delete;
    ~Left() = default;

    virtual std::unique_ptr<ActionResponse> Act(Dungeon_mt& a_dungeon, Player& a_player) const override;

private:
};
}  // namespace experis