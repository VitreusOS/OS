#include "Graphics.hpp"

#include "ExternalHeaders/Stivale2.h"
#include "Shared.h"
#include "StivaleUtil.hpp"
#include "Debug.hpp"

#include <emmintrin.h>

#define fb StivaleFindTag<stivale2_struct_tag_framebuffer>(&Information)

using namespace HAL;

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

Size Graphics::size() const
{
    return Size{fb->framebuffer_width, fb->framebuffer_height};
}

inline auto ccolor(Color c)
{
    return (c.r << fb->red_mask_shift)
        + (c.g << fb->green_mask_shift)
        + (c.b << fb->blue_mask_shift);
}

void Graphics::setPixel(Pos p, Color c)
{
    auto base = (fb->framebuffer_pitch/4 * p.y) + p.x;

    volatile uint32_t* data = (uint32_t*)(void*)fb->framebuffer_addr;

    data[base] = ccolor(c);
}

void Graphics::drawRect(Rect r, Color c)
{
    volatile uint32_t* data = (uint32_t*)(void*)fb->framebuffer_addr;

#pragma clang loop vectorize(enable)
    for (auto y = r.pos.y; y < r.pos.y + r.size.h; y++) {
        for (auto x = r.pos.x; x < r.pos.x + r.size.w; x++) {
            const auto base = (fb->framebuffer_pitch/4 * y) + x;

            data[base] = ccolor(c);
        }
    }
}
