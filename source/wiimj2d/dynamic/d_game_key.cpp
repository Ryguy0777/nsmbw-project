// d_game_key.cpp
// NSMBW: 0x800B5930 - 0x800B5B50

#include "d_game_key.h"
#include "machine/m_pad.h"

#include <dynamic/d_game_key_core.h>
#include <machine/m_heap.h>

static bool s_isInit = false;

[[address_data(0x8042A230)]]
dGameKey_c* dGameKey_c::m_instance = createInstance(mHeap::g_gameHeaps[0]);

[[address(0x800B5930)]]
dGameKey_c* dGameKey_c::createInstance(EGG::Heap* heap)
{
    EGG::Heap* oldHeap = mHeap::setCurrentHeap(heap);

    if (m_instance != nullptr) {
        delete m_instance;
    }

    m_instance = new dGameKey_c();

    mHeap::setCurrentHeap(oldHeap);

    return m_instance;
}

[[address(0x800B5980)]]
dGameKey_c::dGameKey_c()
{
    static constexpr mPad::CH_e s_channels[CORE_COUNT] = {
      mPad::CH_e::CHAN_0,    mPad::CH_e::CHAN_1,    mPad::CH_e::CHAN_2,    mPad::CH_e::CHAN_3,
      mPad::CH_e::CHAN_GC_0, mPad::CH_e::CHAN_GC_1, mPad::CH_e::CHAN_GC_2, mPad::CH_e::CHAN_GC_3,
    };

    for (int i = 0; i < CORE_COUNT; i++) {
        mpCores[i] = new dGameKeyCore_c(s_channels[i]);
    }

    s_isInit = true;
}

/* VT+0x8 */
[[address(0x800B5A00)]]
dGameKey_c::~dGameKey_c()
{
    // Original class only had 4
    int coreCount = s_isInit ? CORE_COUNT : 4;
    for (int i = 0; i < coreCount; i++) {
        delete mpCores[i];
    }

    m_instance = nullptr;
}

[[address(0x800B5AB0)]]
void dGameKey_c::allclear()
{
    for (int i = 0; i < CORE_COUNT; i++) {
        mpCores[i]->allclear();
    }
}

[[address(0x800B5B00)]]
int dGameKey_c::read()
{
    for (int i = 0; i < CORE_COUNT; i++) {
        mpCores[i]->read();
    }
    return 0;
}