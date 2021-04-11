#include "Debug.hpp"
#include "VitreusCorConfig.h"

#include "Kernel.hpp"

void Main() {
    HAL::Debug debugger;

    debugger << "Hi, I'm VitreusCore running on the following architecture: " << Architecture;

    while (true) {
        asm volatile("hlt");
    }
}