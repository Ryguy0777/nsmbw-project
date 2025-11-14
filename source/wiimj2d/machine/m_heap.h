#pragma once

#include <egg/core/eggHeap.h>

namespace mHeap
{

/* 0x8016E630 */
EGG::Heap* setCurrentHeap(EGG::Heap* heap);

extern EGG::Heap* g_gameHeaps[3];

class ScopeHeap_c
{
public:
    inline ScopeHeap_c(EGG::Heap* heap)
      : mOldHeap(setCurrentHeap(heap))
    {
    }

    inline ScopeHeap_c(int heap)
      : ScopeHeap_c(g_gameHeaps[0])
    {
    }

    inline ~ScopeHeap_c()
    {
        setCurrentHeap(mOldHeap);
    }

private:
    EGG::Heap* const mOldHeap;
};

} // namespace mHeap
