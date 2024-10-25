// m_heap.cpp
// NSMBW .bss: 0x80377F48 - 0x80377F58

#include "m_heap.h"

namespace mHeap
{

EXTERN_DATA(
  0x80377F48, //
  EGG::Heap* g_gameHeaps[3]
);

} // namespace mHeap