#pragma once
#include "ActionResponse.h"
#include <string>

namespace experis
{
// Don't forget to const :D
class StringActionResponse : public ActionResponse
{
public:
    explicit StringActionResponse(const std::string& a_reply);
    StringActionResponse(const StringActionResponse& a_other) = delete;
    StringActionResponse& operator=(const StringActionResponse& a_other) = delete;
    ~StringActionResponse() = default;

    virtual ReplyType GetResponse() override;

private:
    Data m_reply;
    size_t m_dataSize;
};
}  // namespace experis