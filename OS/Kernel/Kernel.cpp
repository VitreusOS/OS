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

    HAL::Color a[] = {
        HAL::Colors::c1,
        HAL::Colors::c2,
        HAL::Colors::c3,
        HAL::Colors::c4,
        HAL::Colors::c5,
        HAL::Colors::c6,
        HAL::Colors::c7,
        HAL::Colors::c8,
        HAL::Colors::c9,
        HAL::Colors::c10,
        HAL::Colors::c11,
        HAL::Colors::c12,
    };

    while (true) {
        for (auto i = 0U; i < (sizeof(a) / sizeof(HAL::Color)); i++) {
            gfx.drawRect(HAL::Rect{
                .size = HAL::Size {
                    .w = sz.w,
                    .h = sz.h
                },
                .pos = HAL::Pos {
                    .x = 0,
                    .y = 0,
                },
            }, a[i]);
        }
    }
}