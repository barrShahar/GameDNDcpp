#pragma once
#include <memory>
namespace experis
{
// Abstract class
using Data = std::unique_ptr<char[]>;
using ReplyType = std::pair<Data, size_t>;
class ActionResponse
{
public:
    explicit ActionResponse() = default;
    ActionResponse(const ActionResponse& a_other) = delete;
    ActionResponse& operator=(const ActionResponse& a_other) = delete;
    virtual ~ActionResponse() = default;

    virtual ReplyType GetResponse() = 0;
private:
};
}  // namespace experis