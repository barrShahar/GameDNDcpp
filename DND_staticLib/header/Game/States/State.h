#pragma once
#include <unordered_map>
#include <memory>
#include "StateBase.h"

namespace experis
{

class State
{
public:
    explicit State() = delete;
    State(const State& a_other) = delete;
    State& operator=(const State& a_other) = delete;
    ~State() = default;

    void SetState(STATE a_newState);
    const STATE GetState() const;

private:
    STATE m_currentState;

};
}  // namespace experis