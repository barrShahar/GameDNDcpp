#include "pch.h"
#include "CoutWriter.h"

experis::CoutWriter::CoutWriter(std::ostream& a_os)
	: m_os { a_os }
{
	// Ctor
}

void experis::CoutWriter::Write(const std::string& a_str)
{
	m_os << a_str;                                                                                                                                                                                                                                                                                                                                                                          
}

void experis::CoutWriter::Write(const char a_char)
{
	m_os << a_char;
}
