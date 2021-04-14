#include "Graphics.hpp"

#include "ExternalHeaders/Stivale2.h"
#include "Shared.h"
#include "StivaleUtil.hpp"

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

void Graphics::setPixel(Pos p, Color c)
{
    auto base = (fb->framebuffer_pitch/4 * p.y) + p.x;

    volatile uint32_t* data = (uint32_t*)(void*)fb->framebuffer_addr;

    data[base] = (c.r << fb->red_mask_shift)
                +(c.g << fb->green_mask_shift)
                +(c.b << fb->blue_mask_shift);
}
