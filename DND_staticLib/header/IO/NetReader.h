#pragma once
#include "Reader.h"
#include "SimpleNetMT.h"

namespace experis
{
class NetReader : public Reader
{
public:
    explicit NetReader(simplenet::SimpleNetMT::Connection& a_connection);
    NetReader(const NetReader& a_other) = delete;
    NetReader& operator=(const NetReader& a_other) = delete;
    ~NetReader() = default;

    virtual std::string ReadLine() const override;

private:
    simplenet::SimpleNetMT::Connection& m_connection;
};
}  // namespace experis