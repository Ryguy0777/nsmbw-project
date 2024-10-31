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
#include <machine/m_fader.h>

dScBoot_c::CODE_REGION_e dScBoot_c::m_codeRegion;

[[address(0x8015C550)]]
int dScBoot_c::create_()
{
    dSys_c::setClearColor(nw4r::ut::Color{0, 0, 0, 255});
    dSys_c::setFrameRate(1);

    dScene_c::setFadeInFrame(30);
    dScene_c::setFadeOutFrame(30);

    dGameCom::initRandomSeed();

    new dResMng_c();
    new dInfo_c();

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
