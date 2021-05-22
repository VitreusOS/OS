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
constexpr Color c1 = {233, 58, 154};
constexpr Color c2 = {233, 61, 88};
constexpr Color c3 = {233, 99, 58};
constexpr Color c4 = {239, 151, 60};
constexpr Color c5 = {232, 203, 44};
constexpr Color c6 = {182, 229, 33};
constexpr Color c7 = {61, 212, 37};
constexpr Color c8 = {0, 212, 133};
constexpr Color c9 = {0, 211, 184};
constexpr Color c10 = {61, 174, 233};
constexpr Color c11 = {184, 117, 220};
constexpr Color c12 = {146, 110, 228};

};


struct Size
{
    uint64_t w, h;
};

struct Pos
{
    uint64_t x, y;
};

struct Rect
{
    Size size;
    Pos pos;

    Rect(uint64_t x, uint64_t y, uint64_t w, uint64_t h) : size{w,h}, pos{x,y}
    {
    }
};

class Graphics
{

public:
    Graphics();
    ~Graphics();

    Size size() const;

    void setPixel(Pos p, Color c);
    inline void drawRect(Rect r, Color c) {
        for (auto x = r.pos.x; x < r.pos.x+r.size.w; x++) {
            for (auto y = r.pos.y; y < r.pos.y+r.size.h; y++) {
                setPixel(Pos{x, y}, c);
            }
        }
    }
};

};
