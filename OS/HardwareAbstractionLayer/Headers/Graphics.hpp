#pragma once

#include <stdint.h>

namespace HAL
{

struct Color
{
    uint8_t r, g, b;
};

namespace Colors
{

constexpr Color white = {255, 255, 255};
constexpr Color black = {0, 0, 0};

};


struct Size
{
    uint64_t h, w;
};

struct Pos
{
    uint64_t x, y;
};

class Graphics
{

public:
    Graphics();
    ~Graphics();

    Size size() const;

    void setPixel(const Pos& p, const Color& c);
};

};
