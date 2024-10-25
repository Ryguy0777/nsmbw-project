// m_pad.cpp
// NSMBW: 0x8016F330 - 0x8016F880

#include "m_pad.h"

[[address(0x8016F570)]]
void mPad::setCurrentChannel(CH_e chan);

EXTERN_DATA(
  0x8042A748, //
  EGG::CoreController* mPad::g_currentCore
);