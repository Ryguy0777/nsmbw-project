#pragma once

#include "OSContext.h"

extern "C" {

struct OSThread;

struct OSThreadQueue {
    SIZE_ASSERT(0x8);

    /* 0x0 */ OSThread* head;
    /* 0x4 */ OSThread* tail;
};

struct OSMutex;

struct OSMutexQueue {
    SIZE_ASSERT(0x8);

    /* 0x0 */ OSMutex* head;
    /* 0x4 */ OSMutex* tail;
};

struct OSThread {
    SIZE_ASSERT(0x318);

    /* 0x000 */ OSContext context;
    /* 0x2C8 */ u16 state;
    /* 0x2CA */ u16 flags;
    /* 0x2CC */ s32 suspend;
    /* 0x2D0 */ s32 priority;
    /* 0x2D4 */ s32 base;
    /* 0x2D8 */ u32 val;
    /* 0x2DC */ OSThreadQueue* queue;
    /* 0x2E0 */ OSThread* next;
    /* 0x2E4 */ OSThread* prev;
    /* 0x2E8 */ OSThreadQueue joinQueue;
    /* 0x2F0 */ OSMutex* mutex;
    /* 0x2F4 */ OSMutexQueue mutexQueue;
    /* 0x2FC */ OSThread* nextActive;
    /* 0x300 */ OSThread* prevActive;
    /* 0x304 */ void* stackBegin;
    /* 0x308 */ void* stackEnd;
    /* 0x30C */ s32 error;
    /* 0x310 */ void* specific[2];
};

} // extern "C"