#include "pch.h"
#include "Writer.h"

namespace experis
{
Writer& experis::Writer::operator<<(const std::string& a_str)
{
    Write(a_str);
    return *this;
}
Writer & Writer::operator<<(const char a_char)
{
    Write(a_char);
    return *this;
}
} // experis
