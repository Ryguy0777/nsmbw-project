#pragma once

#include <egg/core/eggHeap.h>

class dResMng_c
{
public:
    /* 0x800DF8C0 */
    void setRes(const char* dir, const char** files, int count, EGG::Heap* heap);

    /* 0x8042A318 */
    static dResMng_c* m_instance;
};