#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include <nw4r/lyt/Pane.h>

class dCharacterChangeIndicator_c : public dBase_c
{
public:
    /* 0x8076DC80 */
    void UNDEF_8076DC80();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x21C);

    /* 0x21C */ nw4r::lyt::Pane* mp0x21C;
    /* 0x220 */ nw4r::lyt::Pane* mp0x220;
};
