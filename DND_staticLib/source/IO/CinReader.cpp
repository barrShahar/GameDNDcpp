#include "pch.h"
#include "CinReader.h"


namespace experis
{
experis::CinReader::CinReader(std::istream & a_inStream)
	: m_inStream { a_inStream }
{
	// Ctor
}

std::string CinReader::ReadLine() const
{
	std::string returnValue;
	std::getline(m_inStream, returnValue);
	return returnValue;
}

} // experis