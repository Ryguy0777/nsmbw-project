#pragma once

#include "machine/m_allocator.h"
#include <egg/core/eggHeap.h>

class dHeapAllocator_c : public mHeapAllocator_c
{
    SIZE_ASSERT(0x1C);

public:
    /* 0x800690C0 */
    void createFrmHeap(std::size_t size, EGG::Heap* heap, const char*, std::size_t);

    /* 0x800690E0 */
    void adjustFrmHeap();
};