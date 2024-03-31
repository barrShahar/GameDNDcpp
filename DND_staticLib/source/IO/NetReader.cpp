#include "pch.h"
#include "NetReader.h"

namespace experis
{
NetReader::NetReader(simplenet::SimpleNetMT::Connection& a_connection)
    : m_connection { a_connection }
{
}

std::string NetReader::ReadLine() const
{
    return m_connection.ReadLine();
}

} // experis