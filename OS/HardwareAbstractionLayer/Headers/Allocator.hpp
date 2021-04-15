#pragma once

#include <stddef.h>
#include <stdint.h>

namespace HAL {

class Allocator
{

public:
    static Allocator* instance();
    static void init();

    void* allocate(size_t size);
    void free(void* mem);

};


}

void* operator new(size_t foo);
void operator delete(void* addr);
