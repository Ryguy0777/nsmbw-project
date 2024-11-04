#pragma once

#include <egg/core/eggController.h>

namespace mPad
{

enum class CH_e {
    CHAN_0 = 0,
    CHAN_1 = 1,
    CHAN_2 = 2,
    CHAN_3 = 3,

    // GameCube
    CHAN_GC_0 = 4,
    CHAN_GC_1 = 5,
    CHAN_GC_2 = 6,
    CHAN_GC_3 = 7,

    COUNT = 8,
};

#define PAD_CHAN_COUNT 8

static_assert(static_cast<long>(CH_e::COUNT) == PAD_CHAN_COUNT, "CH_e and PAD_CHAN_COUNT mismatch");

/* 0x80377F88 */
extern EGG::CoreController* g_core[PAD_CHAN_COUNT];

/* 0x8042A740 */
extern EGG::CoreControllerMgr* g_padMg;

/* 0x8042A748 */
extern EGG::CoreController* g_currentCore;

/* 0x8042A74C */
extern bool g_IsConnected[PAD_CHAN_COUNT];

/* 0x8042A750 */
extern u32 g_PadFrame;

/* 0x8016F360 */
void beginPad();

/* 0x8016F570 */
void setCurrentChannel(CH_e chan);

/* 0x8016F640 */
void clearWPADInfo(CH_e chan);

/* 0x8016F710 */
int getWPADInfoAsync(CH_e chan);

} // namespace mPad