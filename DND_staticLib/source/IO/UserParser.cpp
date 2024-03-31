#include "pch.h"
#include "UserParser.h"

namespace experis
{
experis::UserParser::UserParser()
	: m_stringToCommands {}
{
	// Ctor
	for (size_t i = 0; i < static_cast<size_t>(COMMAND::SIZE); ++i)
	{
		m_stringToCommands.insert(std::make_pair(COMMAND_STRING[i], static_cast< COMMAND >(i)));
	}
}

std::optional<COMMAND> UserParser::ParseUserInput(const std::string& a_untrusted)
{
	// Looking for the user command in the hash table
	decltype(m_stringToCommands)::iterator it = m_stringToCommands.find(a_untrusted);
	return (it != m_stringToCommands.end()) ? std::optional<COMMAND>(it->second) : std::nullopt;
}

} // experis