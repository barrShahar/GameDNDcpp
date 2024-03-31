#pragma once
#include "Reader.h"
#include <iostream>

namespace experis
{
// Don't forget to const :D
class CinReader : public Reader
{
public:
    explicit CinReader(std::istream& a_inStream);
    CinReader(const CinReader& a_other) = delete;
    CinReader& operator=(const CinReader& a_other) = delete;
    ~CinReader() = default;

    virtual std::string ReadLine() const override;

private:
    std::istream& m_inStream;
};
}  // namespace experis

