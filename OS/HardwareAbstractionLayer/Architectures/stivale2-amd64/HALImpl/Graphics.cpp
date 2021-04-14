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
    auto base = (((fb->framebuffer_width * p.y) + (p.x)) * fb->framebuffer_bpp)/8;

    volatile uint8_t* data = (uint8_t*)(void*)fb->framebuffer_addr;

    data[base] = c.r;
    data[base+1] = c.g;
    data[base+2] = c.b;
}
