#pragma once

#include <dynamic/d_lytbase.h>
#include <machine/m_vec.h>
#include <nw4r/lyt/Picture.h>
#include <state/s_State.h>

class DummyInherit {
public:
    virtual ~DummyInherit() = 0;
};

class dfukidashiInfo_c : public DummyInherit, public LytBase_c
{
    SIZE_ASSERT(0x23C);

    friend class dfukidashiManager_c;

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800B1A50 */
    void SetPosOffset(int playerType, int powerupType);

    /* 0x800B1BD0 */
    void ColorSet();

protected:
    // -----------
    // Member Data
    // -----------

    FILL(0x19C, 0x1DC);

    /* 0x1DC */ mVec3_c mPosOffset;

    FILL(0x1E8, 0x1F4);

    /* 0x1F4 */ nw4r::lyt::Pane* mpPane;

    FILL(0x1F8, 0x1FC);

    /* 0x1FC */ nw4r::lyt::Picture* mpAfterImgUD;
    /* 0x200 */ nw4r::lyt::Picture* mpUpDownImg01;
    /* 0x204 */ nw4r::lyt::Picture* mpAfterImgK;
    /* 0x208 */ nw4r::lyt::Picture* mpKatamukiHand;
    /* 0x20C */ nw4r::lyt::Picture* mpArrow;
    /* 0x210 */ nw4r::lyt::Picture* mpUpDownImg02;

    FILL(0x214, 0x21C);

    /* 0x21C */ int mPlayerID;
    /* 0x220 */ s32 m0x220;

    FILL(0x224, 0x22C);

    /* 0x22C */ int m0x22C;
    /* 0x230 */ int m0x230;
    /* 0x234 */ s32 m0x234;

    FILL(0x238, 0x239);

    /* 0x239 */ bool mDisplayed;
    /* 0x23A */ bool m0x23A;

    FILL(0x23B, 0x23C);

public:
    // ---------
    // State IDs
    // ---------

    sState_Extern(0x80358CD8, dfukidashiInfo_c, Move);

    sState_Extern(0x80358D18, dfukidashiInfo_c, Exit);
};