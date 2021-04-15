#include "Allocator.hpp"
#include "Debug.hpp"

namespace HAL {

constexpr size_t BITMAP_SIZE = 32768;
static bool bitmap[BITMAP_SIZE];
static size_t bitmapSizes[BITMAP_SIZE];
static Allocator t;

[[clang::optnone]] void Allocator::init()
{
    for (size_t i = 0; i < BITMAP_SIZE; i++) {
        bitmap[i] = true;
    }
}

Allocator* Allocator::instance()
{
    return &t;
}

void* Allocator::allocate(size_t size)
{
    for (size_t checkingForInitialEmptyIndex = 0; checkingForInitialEmptyIndex < BITMAP_SIZE; checkingForInitialEmptyIndex++) {
        if (!bitmap[checkingForInitialEmptyIndex]) {
            continue;
        }
        for (size_t checkingForFitsSize = checkingForInitialEmptyIndex; checkingForFitsSize < BITMAP_SIZE; checkingForFitsSize++) {
            if (!bitmap[checkingForFitsSize]) {
                goto outerCont;
            }
        }
        for (size_t currentlySettingField = checkingForInitialEmptyIndex; currentlySettingField < checkingForInitialEmptyIndex + size; currentlySettingField++) {
            bitmap[currentlySettingField] = false;
        }
        bitmapSizes[checkingForInitialEmptyIndex] = size;
        return (void*)checkingForInitialEmptyIndex;
    outerCont:
        ;
    }

    return nullptr;
}

void Allocator::free(void* mem)
{
    auto addr = (size_t)mem;
    auto size = bitmapSizes[(size_t)mem];
    for (auto base = addr; base < addr + size; base++) {
        bitmap[base] = true;
    }
}

}

void* operator new(size_t foo)
{
    return HAL::Allocator::instance()->allocate(foo);
}

void operator delete(void* addr)
{
    HAL::Allocator::instance()->free(addr);
}
