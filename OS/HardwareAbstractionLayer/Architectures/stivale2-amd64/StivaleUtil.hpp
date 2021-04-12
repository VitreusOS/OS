#pragma once

#include "ExternalHeaders/Stivale2.h"

template<typename T>
inline T* StivaleFindTag(stivale2_struct* s) {
    auto inital = (stivale2_tag*) s->tags;
    while (inital != nullptr) {
        if (inital->identifier == T::Tag) {
            return (T*)inital;
        }

        inital = (stivale2_tag*)inital->next;
    }
    return nullptr;
}
