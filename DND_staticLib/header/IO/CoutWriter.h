#pragma once
#include "Writer.h"
#include <iostream>
namespace experis
{

class CoutWriter : public Writer
{
public:
    explicit CoutWriter(std::ostream& a_os);
    CoutWriter(const CoutWriter& a_other) = delete;
    CoutWriter& operator=(const CoutWriter& a_other) = delete;
    ~CoutWriter() = default;

    virtual void Write(const std::string& a_str) override;
    virtual void Write(const char a_char) override;

private:
    std::ostream& m_os;
};
}  // namespace experis