#pragma once
#include "Player.h"
namespace experis
{
class ObserverBase
{
public:
    explicit ObserverBase() = default;
    ObserverBase(const ObserverBase& a_other) = delete;
    ObserverBase& operator=(const ObserverBase& a_other) = delete;
    ~ObserverBase() = default;

    virtual void Notify(const std::string& a_message) = 0;
private:

};
}  // namespace experis