#pragma once
#include "ObserverBase.h"
namespace experis
{
// Don't forget to const :D
class SubjectBase
{
public:
    explicit SubjectBase() = default;
    SubjectBase(const SubjectBase& a_other) = delete;
    SubjectBase& operator=(const SubjectBase& a_other) = delete;
    ~SubjectBase() = default;

    virtual void Register(Player& a_player) = 0;
    virtual void Unregister(Player& a_player) = 0;

    virtual void NotifyAll(const std::string& a_message) = 0;

private:
};
}  // namespace experis