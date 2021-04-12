#include "Debug.hpp"
#include "Graphics.hpp"
#include "VitreusCorConfig.h"

#include "Kernel.hpp"

void Main() {
    HAL::Debug debugger;

    debugger << "Hi, I'm VitreusCore running on the following architecture: " << Architecture;

    HAL::Graphics gfx;
    const auto sz = gfx.size();

    debugger << "\n\t(" << sz.h << ", " << sz.w << ")\n";

    gfx.setPixel({0, 0}, HAL::Colors::white);
    gfx.setPixel({1, 0}, HAL::Colors::white);
    gfx.setPixel({2, 0}, HAL::Colors::white);
    gfx.setPixel({3, 0}, HAL::Colors::white);

    while (true) {
        asm volatile("hlt");
    }
}