#pragma once

#include <Region.h>
#include <egg/core/eggExpHeap.h>
#include <nw4r/ut/Color.h>
#include <revolution/arc.h>

class dSys_c
{
public:
    // Constants and Types
    // ^^^^^^

    using CODE_REGION_e = Region;

public:
    // Static Methods
    // ^^^^^^

    /* 0x800E4940 */
    static void setClearColor(nw4r::ut::Color color);

    /* 0x800E4920 */
    static void setFrameRate(u8 rate);

    static void preCModuleInit(s32 arcEntryNum, ARCHandle* arcHandle);
    static void initCModule();

    static void initCodeRegion();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A370 */
    static EGG::ExpHeap* ms_RootHeapMem1;

    /* 0x8042A374 */
    static EGG::ExpHeap* ms_RootHeapMem2;

    static CODE_REGION_e m_codeRegion;
};
