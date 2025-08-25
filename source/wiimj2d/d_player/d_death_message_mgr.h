#pragma once

#include "d_system/d_a_player_manager.h"
#include "machine/m_2d.h"
#include <nw4r/lyt/ResourceAccessor.h>
#include <nw4r/lyt/Resources.h>
#include <nw4r/lyt/TextBox.h>

class dDeathMsgMgr_c final : public m2d::Base_c
{
public:
    // -------------------
    // Constants and Types
    // -------------------

    static constexpr u32 MAX_MESSAGES = 12;

public:
    // ------------
    // Constructors
    // ------------

    dDeathMsgMgr_c();
    ~dDeathMsgMgr_c() override;

public:
    // ----------------
    // Member Functions
    // ----------------

    void newMessage(const wchar_t* message, daPyMng_c::PlayerType_e player);
    void deleteFront();

    void build(nw4r::lyt::ResourceAccessor* resAcc, nw4r::lyt::DrawInfo* drawInfo);

public:
    // -----------------
    // Virtual Functions
    // -----------------

    virtual void draw() override;

private:
    // -----------
    // Member Data
    // -----------

    nw4r::lyt::TextBox* mTextBox;
    nw4r::lyt::ResBlockSet mResBlockSet;
    nw4r::lyt::DrawInfo* mpDrawInfo;

    u32 mIndex;
    u32 mCount;
    u32 mTimeToLive[MAX_MESSAGES];
};