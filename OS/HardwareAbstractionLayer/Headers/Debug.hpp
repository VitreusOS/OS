#pragma once

#include <stdint.h>

namespace HAL {

class Debug
{

public:
    void write(const char* str);
    void write(uint64_t n);
    void write(char c);
    void write(int i);
    void write(bool b);
};

template<typename T>
Debug& operator<<(Debug& t, T v)
{
    t.write(v);
    return t;
}

}