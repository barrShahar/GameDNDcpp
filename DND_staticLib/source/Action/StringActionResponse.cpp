#include "pch.h"
#include "StringActionResponse.h"

namespace experis
{
experis::StringActionResponse::StringActionResponse(const std::string& a_reply)
	: m_reply { std::make_unique<char[]>(a_reply.size() + 1) }
	, m_dataSize { a_reply.size() }
{
	std::copy(a_reply.begin(), a_reply.end(), m_reply.get());
	m_reply[m_dataSize] = '\0'; // Null-terminate the string
}

ReplyType experis::StringActionResponse::GetResponse()
{
	return std::move(std::make_pair(std::move(m_reply), m_dataSize));
}

}  // experis
