#pragma once

#include <revolution/wpad.h>

extern "C" {

struct KPADVec2D {
    float x;
    float y;
};

struct KPADVec3D {
    float x;
    float y;
    float z;
};

struct KPADStatus {
    SIZE_ASSERT(0xB0);

    /* 0x00 */ u32 hold;
    /* 0x04 */ u32 trigger;
    /* 0x08 */ u32 release;

    /* 0x0C */ KPADVec3D acc;
    /* 0x18 */ float accMagnitude;
    /* 0x1C */ float accVariation;

    /* 0x20 */ KPADVec2D dpdPos;

    FILL(0x28, 0x34);

    /* 0x34 */ KPADVec2D angle;

    FILL(0x3C, 0x54);

    /* 0x54 */ KPADVec2D accVertical;

    /* 0x5C */ WPADDeviceType extensionType;
    /* 0x5D */ s8 error;
    /* 0x5E */ s8 dpdPosValid;
    /* 0x5F */ u8 format;

    /* 0x60 */ KPADVec2D fsStick;

    FILL(0x68, 0xB0);
};

/* 0x801ED4F0 */
int KPADReadEx(WPADChannel chan, KPADStatus* status, u32 count, s32* result);

} // extern "C"