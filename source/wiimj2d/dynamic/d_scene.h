#pragma once

#include "System.h"
#include "d_base.h"

class sPhase_c;

class dScene_c : public dBase_c
{
    SIZE_ASSERT(0x74);

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800E1AA0 */
    dScene_c();

    /* VT+0x48 0x800E1B10 */
    virtual ~dScene_c() override;

public:
    // ---------
    // Functions
    // ---------

    /* 0x800E2040 */
    void setFadeInFrame(u16 frames);

    /* 0x800E2050 */
    void setFadeOutFrame(u16 frames);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x70 */ sPhase_c* mpPhase;

public:
    // -----------
    // Static Data
    // -----------

    /* 0x80428A42 */ static u16 m_nowScene;
};
