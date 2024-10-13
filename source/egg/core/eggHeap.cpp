// eggHeap.cpp
// NSMBW: 0x802B8C80 - 0x802B93E0

#include "eggHeap.h"
#include <string.h>

namespace EGG
{

EXTERN_TEXT(
  0x802B8C80, //
  void Heap::initialize()
);

EXTERN_TEXT_CONSTRUCTOR(
  0x802B8CC0, //
  Heap::Heap(MEMiHeapHead* rvlHeap)
);

EXTERN_TEXT_CONSTRUCTOR(
  0x802B8D60, //
  Heap::~Heap()
);

EXTERN_TEXT(
  0x802B8E00, //
  void* Heap::alloc(u32 size, s32 align, Heap* heap)
);

EXTERN_TEXT(
  0x802B8FC0, //
  Heap* Heap::findHeap(MEMiHeapHead* rvlHeap)
);

EXTERN_TEXT(
  0x802B9060, //
  Heap* Heap::findParentHeap()
);

EXTERN_TEXT(
  0x802B9070, //
  Heap* Heap::findContainHeap(const void* block)
);

EXTERN_TEXT(
  0x802B90B0, //
  void Heap::free(void* block, EGG::Heap* heap)
);

EXTERN_TEXT(
  0x802B9150, //
  void Heap::dispose()
);

EXTERN_TEXT(
  0x802B91B0, //
  void Heap::dump()
);

EXTERN_TEXT(
  0x802B91C0, //
  void Heap::dumpAll()
);

EXTERN_TEXT(
  0x802B92B0, //
  Heap* Heap::becomeCurrentHeap()
);

EXTERN_TEXT(
  0x802B9310, //
  Heap* Heap::_becomeCurrentHeapWithoutLock()
);

} // namespace EGG

EXTERN_TEXT(
  0x802B9350, //
  void* operator new(u32 size)
);

EXTERN_TEXT(
  0x802B9360, //
  void* operator new(u32 size, void* block)
);

EXTERN_TEXT(
  0x802B9370, //
  void* operator new(u32 size, int align)
);

EXTERN_TEXT(
  0x802B9380, //
  void* operator new(u32 size, EGG::Heap* heap, int align)
);

EXTERN_TEXT(
  0x802B9390, //
  void* operator new[](u32 size)
);

EXTERN_TEXT(
  0x802B93A0, //
  void* operator new[](u32 size, int align)
);

EXTERN_TEXT(
  0x802B93B0, //
  void* operator new[](u32 size, EGG::Heap* heap, int align)
);

EXTERN_TEXT(
  0x802B93C0, //
  void operator delete(void* block)
);

EXTERN_TEXT(
  0x802B93D0, //
  void operator delete[](void* block)
);

void operator delete(void* block, u32 size)
{
    operator delete(block);
}