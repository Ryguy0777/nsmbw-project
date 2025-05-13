// eggHeap.cpp
// NSMBW .text: 0x802B8C80 - 0x802B93E0

#include "eggHeap.h"
#include <string.h>

namespace EGG
{

[[address(0x8042B0F0)]]
Heap* Heap::sCurrentHeap;

[[address(0x802B8C80)]]
void Heap::initialize();

[[address(0x802B8CC0)]]
Heap::Heap(MEMiHeapHead* rvlHeap);

[[address(0x802B8D60)]]
Heap::~Heap();

[[address(0x802B8E00)]]
void* Heap::alloc(u32 size, s32 align, Heap* heap);

[[address(0x802B8FC0)]]
Heap* Heap::findHeap(MEMiHeapHead* rvlHeap);

[[address(0x802B9060)]]
Heap* Heap::findParentHeap();

[[address(0x802B9070)]]
Heap* Heap::findContainHeap(const void* block);

[[address(0x802B90B0)]]
void Heap::free(void* block, EGG::Heap* heap);

[[address(0x802B9150)]]
void Heap::dispose();

[[address(0x802B91B0)]]
void Heap::dump();

[[address(0x802B91C0)]]
void Heap::dumpAll();

[[address(0x802B92B0)]]
Heap* Heap::becomeCurrentHeap();

[[address(0x802B9310)]]
Heap* Heap::_becomeCurrentHeapWithoutLock();

} // namespace EGG

[[address(0x802B9350)]]
void* operator new(u32 size);

/* 0x802B9360 */
// Moved to <new>
// void* operator new(u32 size, void* block);

[[address(0x802B9370)]]
void* operator new(u32 size, int align);

[[address(0x802B9380)]]
void* operator new(u32 size, EGG::Heap* heap, int align);

[[address(0x802B9390)]]
void* operator new[](u32 size);

[[address(0x802B93A0)]]
void* operator new[](u32 size, int align);

[[address(0x802B93B0)]]
void* operator new[](u32 size, EGG::Heap* heap, int align);

[[address(0x802B93C0)]]
void operator delete(void* block);

[[address(0x802B93D0)]]
void operator delete[](void* block);

void operator delete(void* block, u32 size)
{
    operator delete(block);
}