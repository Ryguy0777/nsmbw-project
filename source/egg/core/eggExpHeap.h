#pragma once

#include "eggHeap.h"

namespace EGG
{

class ExpHeap : public Heap
{
public:
    /* 0x802B9840 */
    static u32 getSizeForMBlock(const void *block);
};

} // namespace EGG
