#pragma once

#include <machine/m_pad.h>

class dGameKeyCore_c
{
    SIZE_ASSERT(0x94);
    /* 0x0 VTABLE 0x80315910 */

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800B5B50 */
    dGameKeyCore_c(mPad::CH_e channel);

    /* VT+0x8 0x800B5BA0 */
    virtual ~dGameKeyCore_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800B5BE0 */
    void allclear();

    /* 0x800B5CB0 */
    void read();

public:
    FILL(0x04, 0x94);
};