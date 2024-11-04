#pragma once

#include <nw4r/ut/Color.h>
#include <revolution/arc.h>

class dSys_c
{
public:
    //
    // Static Functions
    //

    /* 0x800E4940 */
    static void setClearColor(nw4r::ut::Color color);

    /* 0x800E4920 */
    static void setFrameRate(u8 rate);

    static void preCModuleInit(s32 arcEntryNum, ARCHandle* arcHandle);
    static void initCModule();
};