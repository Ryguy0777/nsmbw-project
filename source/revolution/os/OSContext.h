#pragma once

extern "C" {

struct OSContext {
    SIZE_ASSERT(0x2C8);

    /* 0x000 */ u32 gprs[32];
    /* 0x080 */ u32 cr;
    /* 0x084 */ u32 lr;
    /* 0x088 */ u32 ctr;
    /* 0x08C */ u32 xer;
    /* 0x090 */ f64 fprs[32];
    /* 0x190 */ u32 fpscr_pad;
    /* 0x194 */ u32 fpscr;
    /* 0x198 */ u32 srr0;
    /* 0x19C */ u32 srr1;
    /* 0x1A0 */ u16 mode;
    /* 0x1A2 */ u16 state;
    /* 0x1A4 */ u32 gqrs[8];
    /* 0x1C4 */ u32 psf_pad;
    /* 0x1C8 */ f64 psfs[32];
};

} // extern "C"