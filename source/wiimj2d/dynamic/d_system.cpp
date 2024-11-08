// d_system.cpp
// NSMBW: 0x800E46E0 - 0x800E5480

#include "d_system.h"

#include <dynamic/actor/d_a_player_manager.h>
#include <dynamic/d_remocon_mng.h>
#include <dynamic/scene/d_s_boot.h>
#include <egg/core/eggController.h>
#include <machine/m_heap.h>
#include <machine/m_pad.h>
#include <revolution/dvd.h>
#include <revolution/pad.h>

EXTERN_SYMBOL(0x800E46E0, "#CAE882A9");

EXTERN_SYMBOL(0x800E4750, "beginRender__6dSys_cFv");

EXTERN_SYMBOL(0x800E4770, "endRender__6dSys_cFv");

EXTERN_SYMBOL(0x800E47D0, "beginFrame__6dSys_cFv");

EXTERN_SYMBOL(0x800E4820, "onBeginFrame__Q23EGG17ConfigurationDataFv");

EXTERN_SYMBOL(0x800E4830, "endFrame__6dSys_cFv");

EXTERN_SYMBOL(0x800E4880, "onEndFrame__Q23EGG17ConfigurationDataFv");

EXTERN_SYMBOL(0x800E4890, "setBlack__6dSys_cFb");

EXTERN_SYMBOL(0x800E4910, "calcAudio__6dSys_cFv");

EXTERN_SYMBOL(0x800E4920, "setFrameRate__6dSys_cFUc");

EXTERN_SYMBOL(0x800E4940, "setClearColor__6dSys_cFQ34nw4r2ut5Color");

EXTERN_SYMBOL(0x800E4990, "getClearColor__6dSys_cFv");

EXTERN_SYMBOL(0x800E49C0, "create__6dSys_cFv");

EXTERN_SYMBOL(0x800E4C40, "setPosParam__Q23EGG14CoreControllerFff");

EXTERN_SYMBOL(
  0x800E4C50, "initialize__Q33EGG126TSystem<Q23EGG5Video,Q23EGG12AsyncDisplay,Q23EGG10XfbManager,"
              "Q23EGG14SimpleAudioMgr,Q23EGG12SceneManager,Q23EGG12ProcessMeter>13ConfigurationFv"
);

EXTERN_SYMBOL(0x800E4EC0, "myDylinkInitPhase_0__22@unnamed@d_system_cpp@FPv");

EXTERN_SYMBOL(0x800E4EF0, "myDylinkInitPhase_1__22@unnamed@d_system_cpp@FPv");

EXTERN_SYMBOL(0x800E4F20, "myDylinkInitPhase_4__22@unnamed@d_system_cpp@FPv");

EXTERN_SYMBOL(0x800E4F50, "execute__6dSys_cFv");

EXTERN_SYMBOL(0x800E50C0, "createEffectManagerPhase1__7dSystemFPv");

EXTERN_SYMBOL(0x800E5170, "createEffectManagerPhase2__7dSystemFPv");

EXTERN_SYMBOL(0x800E51E0, "createFontManagerPhase__7dSystemFPv");

EXTERN_SYMBOL(0x800E5220, "createMessageManagerPhase__7dSystemFPv");

EXTERN_SYMBOL(0x800E52B0, "fixArena__7dSystemFv");

EXTERN_SYMBOL(0x800E5310, "fixHeapsSub__7dSystemFPQ23EGG7ExpHeapi");

EXTERN_SYMBOL(0x800E53E0, "fixHeaps__7dSystemFv");

EXTERN_SYMBOL(0x800E5440, "__sinit_\\d_system_cpp");

void dSys_c::preCModuleInit(s32 arcEntryNum, ARCHandle* arcHandle)
{
    dScBoot_c::initCodeRegion();

    __DVDEXInit(arcEntryNum, arcHandle);
}

void dSys_c::initCModule()
{
    EGG::CoreControllerMgr::recreateInstance();

    mPad::create();

    dRemoconMng_c::recreate(mHeap::g_gameHeaps[0]);

    dScBoot_c::m_instance->recreate();

    daPyMng_c::initGame();
}

extern "C" int preinit(s32 param1, void* param2)
{
    dSys_c::preCModuleInit(param1, reinterpret_cast<ARCHandle*>(param2));

    return 0;
}

extern "C" int main()
{
    dSys_c::initCModule();

    return 0;
}
