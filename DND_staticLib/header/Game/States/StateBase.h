#pragma once
#include "Writer.h"
#include "Reader.h"
#include "Player.h"
#include "tuple"
namespace experis
{
enum class STATE
{
    WAITING_FOR_INPUT,
    PRINT_ROOM
};

class StateBase
{
public:
    explicit StateBase() = delete;
    StateBase(const StateBase& a_other) = delete;
    StateBase& operator=(const StateBase& a_other) = delete;
    ~StateBase() = default;


private:

};
}  // namespace experis