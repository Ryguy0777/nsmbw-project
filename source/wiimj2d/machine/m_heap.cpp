// m_heap.cpp
// NSMBW .bss: 0x80377F48 - 0x80377F58

#include "m_heap.h"

namespace mHeap
{

[[address_data(0x80377F48)]]
EGG::Heap* g_gameHeaps[3];

[[address(0x8016E630)]]
EGG::Heap* setCurrentHeap(EGG::Heap* heap);

} // namespace mHeap