#pragma once
namespace experis
{
// Don't forget to const :D
class StateInput
{
public:
    explicit StateInput() = delete;
    StateInput(const StateInput& a_other) = delete;
    StateInput& operator=(const StateInput& a_other) = delete;
    ~StateInput() = default;

private:
};
}  // namespace experis