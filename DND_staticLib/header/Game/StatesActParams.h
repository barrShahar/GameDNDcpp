#pragma once
#include "GameParams.h"
namespace experis
{


// ACTS
// Do not change order 
#define FOREACH_COMMAND(COMMAND) \
        COMMAND(left)    \
        COMMAND(right)   \
        COMMAND(walk)    \
        COMMAND(look)    \
        COMMAND(talk)    \
        COMMAND(shout)   \
        COMMAND(help)    \
        COMMAND(take)    \
        COMMAND(attack)  \
        COMMAND(quit)    \
        COMMAND(SIZE)


#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum class COMMAND
{
    FOREACH_COMMAND(GENERATE_ENUM)
};

static const char *COMMAND_STRING[] =
{
    FOREACH_COMMAND(GENERATE_STRING)
};

enum class STATE // Do not change order!! GameExecuter depends on it
{
    INIT,
    WAITING_FOR_INPUT,
    STRING_ACT,
    GET_INPUT,
    HELP,
    ATTACK,
    EXIT
};

/* ACTION in cstring
#define GENERATE_ENUM(ENUM) ENUM,

static const char *ACTION_STRING[] =
{
    FOREACH_ACTION(GENERATE_STRING)
};
*/
}