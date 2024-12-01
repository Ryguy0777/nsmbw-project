#pragma once

#include "OSThread.h"

extern "C" {

struct OSMutex {
    SIZE_ASSERT(0x18);

    /* 0x00 */ OSThreadQueue queue;
    /* 0x08 */ OSThread* thread;
    /* 0x0C */ s32 lock;
    /* 0x10 */ OSMutex* next;
    /* 0x14 */ OSMutex* prev;
};

} // extern "C"