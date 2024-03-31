#pragma once
namespace experis
{
using Number = unsigned int;


static constexpr Number NUMBER_ZERO = 0;

static constexpr Number ASCII_AXIS_X = 40;
static constexpr Number ASCII_AXIS_Y = 30;


// Do not change order 
#define FOREACH_DIRECTION(Direction) \
        Direction(NORTH)    \
        Direction(WEST)     \
        Direction(SOUTH)    \
        Direction(EAST)     \
        Direction(SIZE)

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum class Direction
{
    FOREACH_DIRECTION(GENERATE_ENUM)
};

static const char *DIRECTION_STRING[] =
{
    FOREACH_DIRECTION(GENERATE_STRING)
};

enum class TREASURE_TYPE
{
    MAGIC_YOUTH_POTION,
    SWORD,
    GUN,
    SIZE
};

struct AttackPlayerResponse
{
    AttackPlayerResponse(bool a_isValid);
    bool m_isValid;
    Number m_otherPlayerRemainingLife;
    Number m_PlayerRemainingLife;

    Number m_DamageToPlayer;
    Number m_DamageToOtherPlayer;
    bool m_isAttackedPlayerAlive;
    bool m_isAttackerPlayerAlive;
    Number GetOtherPlayerLifePoints();
    Number GetDamageToThisPlayer() const;
};
struct AttackDragonResponse
{
    Number m_dragonRemainingLife;
    Number m_damageToPlayer;
    Number GetDragonRemainingLifePoints();
    Number GetDamageToPlayer() const;


};

// Parameters for randomly allocate maze (not implemented yet)
static constexpr int THERE_IS_A_DRAGON = -1;
static constexpr Number NUMBER_OF_DOORS_PER_ROOM = 4;
static constexpr double IS_DOOR_PROBABILITY = 0.3;
static constexpr double IS_DRAGON_PROBABILITY = 0.3;
static constexpr double IS_TREASURE_PROBABILITY = 0.3;

} // experis