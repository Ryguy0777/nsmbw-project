#pragma once

#include <egg/core/eggController.h>

namespace mPad
{

enum CH_e {
    CHAN_0 = 0,
    CHAN_1 = 1,
    CHAN_2 = 2,
    CHAN_3 = 3,
};

/* 0x8016F570 */
void setCurrentChannel(CH_e chan);

/* 0x8042A748 */
extern EGG::CoreController* g_currentCore;

}