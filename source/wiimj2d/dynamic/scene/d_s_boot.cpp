// d_s_boot.cpp
// NSMBW: 0x8015C270 - 0x8015F270

#include "d_s_boot.h"

#include <dynamic/d_ControllerInformation.h>
#include <dynamic/d_WiiStrap.h>
#include <dynamic/d_game_common.h>
#include <dynamic/d_info.h>
#include <dynamic/d_resource_manager.h>
#include <dynamic/d_scene.h>
#include <dynamic/d_system.h>
#include <egg/core/eggHeap.h>
#include <machine/m_fader.h>
#include <machine/m_heap.h>

[[address(0x8042A620)]]
dScBoot_c* dScBoot_c::m_instance;

dScBoot_c::CODE_REGION_e dScBoot_c::m_codeRegion;

int dScBoot_c::recreate()
{
    u8 dInfo_data[dInfo_c::ORIGINAL_SIZE];
    bool dInfo_copy = false;
    if (dInfo_c::m_instance != nullptr) {
        std::memcpy(dInfo_data, static_cast<void*>(dInfo_c::m_instance), dInfo_c::ORIGINAL_SIZE);
        operator delete(dInfo_c::m_instance);
        dInfo_copy = true;
    }

    dInfo_c* newInfo = new (mHeap::g_gameHeaps[0], alignof(dInfo_c)) dInfo_c();
    if (dInfo_copy) {
        std::memcpy(static_cast<void*>(newInfo), dInfo_data, dInfo_c::ORIGINAL_SIZE);
    }

    return 1;
}

[[address(0x8015D010)]]
void dScBoot_c::executeState_WiiStrapFadeOut()
{
    if (!mFader_c::isStatus(mFaderBase_c::OPAQUE)) {
        return;
    }

    if (mControllerInformation == nullptr || !mControllerInformation->mReady) {
        return;
    }

    mWiiStrap->mVisible = false;

    changeState(StateID_ControllerInformationFadeIn);
}

void dScBoot_c::initCodeRegion()
{
    u8 c;
    switch (*reinterpret_cast<u8*>(0x8000423A)) {
    case 0xFF:
        // PAL (P)
        c = *reinterpret_cast<u8*>(0x800CF287);
        if (c == 0x30) {
            m_codeRegion = CODE_REGION_e::P1;
        } else /* if (c == 0x38) */ {
            m_codeRegion = CODE_REGION_e::P2;
        }
        break;

    case 0xFC:
        // USA (E)
        c = *reinterpret_cast<u8*>(0x800CF197);
        if (c == 0x30) {
            m_codeRegion = CODE_REGION_e::E1;
        } else /* if (c == 0x38) */ {
            m_codeRegion = CODE_REGION_e::E2;
        }
        break;

    case 0xF9:
        // JPN (J)
        c = *reinterpret_cast<u8*>(0x800CF117);
        if (c == 0x30) {
            m_codeRegion = CODE_REGION_e::J1;
        } else /* if (c == 0x38) */ {
            m_codeRegion = CODE_REGION_e::J2;
        }
        break;

    case 0xC8:
        // KOR (K)
        m_codeRegion = CODE_REGION_e::K;
        return;

    case 0xAC:
        // TWN (W)
        m_codeRegion = CODE_REGION_e::W;
        return;

    case 0x55:
        // CHN (C)
        m_codeRegion = CODE_REGION_e::C;
        return;
    }
}
