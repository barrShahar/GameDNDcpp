#pragma once
#include "Writer.h"
#include "SimpleNetMT.h"

namespace experis
{
// Don't forget to const :D
class NetWriter : public Writer
{
public:
    explicit NetWriter(simplenet::SimpleNetMT::Connection& a_connection);
    NetWriter(const NetWriter& a_other) = delete;
    NetWriter& operator=(const NetWriter& a_other) = delete;
    ~NetWriter() = default;

    virtual void Write(const std::string& a_str);
    virtual void Write(const char a_char);

private:
    simplenet::SimpleNetMT::Connection& m_connection;

};
}  // namespace experis