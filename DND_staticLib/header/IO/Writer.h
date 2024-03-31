#pragma once
#include <string>
namespace experis
{
// Don't forget to const :D
class Writer
{
public:
    explicit Writer() = default;
    Writer(const Writer& a_other) = delete;
    Writer& operator=(const Writer& a_other) = delete;
    virtual ~Writer() = default;


    virtual void Write(const std::string& a_str) = 0;
    virtual void Write(const char a_char) = 0;
    virtual Writer& operator<<(const std::string& a_str);
    virtual Writer& operator<<(const char a_char);
private:
};
}  // namespace experis