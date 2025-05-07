#pragma once

#include <dynamic/d_base.h>
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

    FILL(0x070, 0x21C);

    /* 0x21C */ nw4r::lyt::Pane* mp0x21C;
    /* 0x220 */ nw4r::lyt::Pane* mp0x220;
};