#include "pch.h"
#include "NetWriter.h"

experis::NetWriter::NetWriter(simplenet::SimpleNetMT::Connection & a_connection)
	: m_connection { a_connection }
{
	// Ctor
}

void experis::NetWriter::Write(const std::string & a_str)
{
	m_connection.Write(a_str);
}

void experis::NetWriter::Write(const char a_char)
{
	m_connection.Write(std::string{ a_char });
}
