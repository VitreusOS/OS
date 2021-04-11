#pragma once

namespace HAL {

class Debug
{

public:
    void write(const char* str);
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