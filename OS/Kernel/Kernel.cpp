#include "Debug.hpp"
#include "Graphics.hpp"
#include "VitreusCorConfig.h"

#include "Allocator.hpp"
#include "Kernel.hpp"

auto DrawBackground(HAL::Graphics& it, const HAL::Size& sz)
{
    it.drawRect(HAL::Rect(0, 0, sz.w, sz.h), HAL::Color{ 144, 144, 144 });

    it.drawRect(HAL::Rect(0, 0, sz.w, 1), HAL::Color{ 255, 255, 255 });
    it.drawRect(HAL::Rect(0, 1, sz.w, 17), HAL::Color{ 221, 221, 221 });
    it.drawRect(HAL::Rect(0, 18, sz.w, 1), HAL::Color{ 153, 153, 153 });
    it.drawRect(HAL::Rect(0, 19, sz.w, 1), HAL::Color{ 18, 18, 18 });
}

[[clang::optnone]] void Main() {
    HAL::Debug debugger;

    HAL::Allocator::init();

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

    DrawBackground(gfx, sz);

    while (true) {
    }
}