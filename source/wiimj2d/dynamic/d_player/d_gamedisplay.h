#pragma once

#include <dynamic/d_actor_state.h>
#include <dynamic/d_base.h>
#include <dynamic/d_lytbase.h>
#include <dynamic/d_lyttextbox.h>
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include <nw4r/lyt/TexMap.h>
#include <revolution/gx/GXStruct.h>
#include <state/s_StateMgr.h>

class dGameDisplay_c : public dBase_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x80157850 */
    dGameDisplay_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80158830 */
    bool createLayout();

    /* 0x801586C0 */
    void RestDispSetup();

    /* 0x801591F0 */
    bool Effect1Up(int paneIndex);

    /* 0x80159390 */
    void GrayColorSet(int player);

    /* 0x80159620 */
    void ReturnGrayColorSet(int player);

    /* 0x801599C0 */
    void setPlayNum(int* playNum);

    void updatePlayNum(int* playNum);

    /* 0x80159AA0 */
    void setCoinNum(int coinNum);

    /* 0x80159C00 */
    void setTime(int time);

    /* 0x80159C30 */
    void setCollect();

    /* 0x80159DF0 */
    void setScore(int score);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x330);

    // Moved
    /* 0x330 */ s16 mPlayerRGBA0_Removed[4][4];
    /* 0x350 */ s16 mPlayerRGBA1_Removed[4][4];
    /* 0x370 */ s16 mPlayerRGBA2_Removed[4][4];

    /* 0x390 */
    sStateMgr_c<dGameDisplay_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    // Moved
    /* 0x3CC */ int mPlayNum_Removed[4];
    /* 0x3DC */ int mCoinNum;
    /* 0x3E0 */ int mTime;
    /* 0x3E4 */ s32 m0x3E4;
    /* 0x3E8 */ int mScore;

    FILL(0x3EC, 0x414);

    /* 0x414 */ s32 m0x414;

    FILL(0x418, 0x424);

    // Changed from int to s8
    /* 0x424 */ s8 mEffectTimer[16];

    FILL(0x434, 0x490);

    /* 0x490 */ nw4r::lyt::Pane* mpRootPane;

    //
    // Panes
    //

    union {
        struct {
            /* 0x494 */ nw4r::lyt::Picture* mpPicture_CollectOff00;
            /* 0x498 */ nw4r::lyt::Picture* mpPicture_Collection00;
            /* 0x49C */ nw4r::lyt::Picture* mpPicture_CollectOff01;
            /* 0x4A0 */ nw4r::lyt::Picture* mpPicture_Collection01;
            /* 0x4A4 */ nw4r::lyt::Picture* mpPicture_CollectOff02;
            /* 0x4A8 */ nw4r::lyt::Picture* mpPicture_Collection02;
            /* 0x4AC */ nw4r::lyt::Picture* mpPicture_MarioIcon;
            /* 0x4B0 */ nw4r::lyt::Picture* mpPicture_LuigiIcon;
            /* 0x4B4 */ nw4r::lyt::Picture* mpPicture_KinoBIcon;
            /* 0x4B8 */ nw4r::lyt::Picture* mpPicture_KinoYIcon;
        };

        /* 0x494 */ nw4r::lyt::Picture* mpaPictures[10];
    };

    union {
        struct {
            /* 0x4BC */ LytTextBox_c* mpTextBox_Left00;
            /* 0x4C0 */ LytTextBox_c* mpTextBox_X01;
            /* 0x4C4 */ LytTextBox_c* mpTextBox_Left01;
            /* 0x4C8 */ LytTextBox_c* mpTextBox_X02;
            /* 0x4CC */ LytTextBox_c* mpTextBox_Left02;
            /* 0x4D0 */ LytTextBox_c* mpTextBox_X03;
            /* 0x4D4 */ LytTextBox_c* mpTextBox_Left03;
            /* 0x4D8 */ LytTextBox_c* mpTextBox_X04;
            /* 0x4DC */ LytTextBox_c* mpTextBox_Coins;
            /* 0x4E0 */ LytTextBox_c* mpTextBox_Timer;
            /* 0x4E4 */ LytTextBox_c* mpTextBox_Score;
        };

        /* 0x4BC */ LytTextBox_c* mpaTextBoxes[11];
    };

    union {
        struct {
            /* 0x4E8 */ nw4r::lyt::Pane* mpPane_OtasukeInfo;
            /* 0x4EC */ nw4r::lyt::Pane* mpPane_OtasukeChu;
            /* 0x4F0 */ nw4r::lyt::Pane* mpPane_Left;
            /* 0x4F4 */ nw4r::lyt::Pane* mpPane_Coin;
            /* 0x4F8 */ nw4r::lyt::Pane* mpPane_Collection;
            /* 0x4FC */ nw4r::lyt::Pane* mpPane_Score;
            /* 0x500 */ nw4r::lyt::Pane* mpPane_AreaZanki;
            /* 0x504 */ nw4r::lyt::Pane* mpPane_AreaCoin;
            /* 0x508 */ nw4r::lyt::Pane* mpPane_AreaScore;
            /* 0x50C */ nw4r::lyt::Pane* mpPane_MarioIcon;
            /* 0x510 */ nw4r::lyt::Pane* mpPane_LuigiIcon;
            /* 0x514 */ nw4r::lyt::Pane* mpPane_KinoBIcon;
            /* 0x518 */ nw4r::lyt::Pane* mpPane_KinoYIcon;
            /* 0x51C */ nw4r::lyt::Pane* mpPane_Coin2;
            /* 0x520 */ nw4r::lyt::Pane* mpPane_Time;
            /* 0x524 */ nw4r::lyt::Pane* mpPane_ProportionL;
            /* 0x528 */ nw4r::lyt::Pane* mpPane_ProportionR;
            /* 0x52C */ nw4r::lyt::Pane* mpPane_Coin1st;
            /* 0x530 */ nw4r::lyt::Pane* mpPane_Coin2nd;
            /* 0x534 */ nw4r::lyt::Pane* mpPane_Coin3rd;
        };

        /* 0x4E8 */ nw4r::lyt::Pane* mpaPanes[20];
    };

    FILL(0x538, 0x5A4);
    OFFSET_ASSERT(0x5A4);

#define dGameDisplay_c_EXTRA_PLAYER_COUNT 4
    static constexpr u32 EXTRA_PLAYER_COUNT = dGameDisplay_c_EXTRA_PLAYER_COUNT;

#define OFFSET_dGameDisplay_c_mPlayerRGBA0 0x5A4
    GXColorS10 mPlayerRGBA[4 + EXTRA_PLAYER_COUNT];

#define OFFSET_dGameDisplay_c_mPlayerRGBA1 0x5A4 + (4 + dGameDisplay_c_EXTRA_PLAYER_COUNT) * 0x8
    GXColorS10 mPlayerRGBA2[4 + EXTRA_PLAYER_COUNT];

#define OFFSET_dGameDisplay_c_mPlayerRGBA2 0x5A4 + (4 + dGameDisplay_c_EXTRA_PLAYER_COUNT) * 0x10
    GXColorS10 mPlayerRGBA3[4 + EXTRA_PLAYER_COUNT];

    int mPlayNum[4 + EXTRA_PLAYER_COUNT];
    bool mPlayerGray[4 + EXTRA_PLAYER_COUNT];
    bool mPlayNumSet;

    union {
        struct {
            nw4r::lyt::Picture* mpPicture_KinopicoIcon;
            nw4r::lyt::Picture* mpPicture_Player05Icon;
            nw4r::lyt::Picture* mpPicture_Player06Icon;
            nw4r::lyt::Picture* mpPicture_Player07Icon;
        };

        nw4r::lyt::Picture* mpaExPictures[EXTRA_PLAYER_COUNT];
    };

    union {
        struct {
            LytTextBox_c* mpTextBox_Left04;
            LytTextBox_c* mpTextBox_X05;
            LytTextBox_c* mpTextBox_Left05;
            LytTextBox_c* mpTextBox_X06;
            LytTextBox_c* mpTextBox_Left06;
            LytTextBox_c* mpTextBox_X07;
            LytTextBox_c* mpTextBox_Left07;
            LytTextBox_c* mpTextBox_X08;
        };

        LytTextBox_c* mpaExTextBoxes[EXTRA_PLAYER_COUNT * 2];
    };

    union {
        struct {
            nw4r::lyt::Pane* mpPane_KinopicoIcon;
            nw4r::lyt::Pane* mpPane_Player05Icon;
            nw4r::lyt::Pane* mpPane_Player06Icon;
            nw4r::lyt::Pane* mpPane_Player07Icon;
        };

        nw4r::lyt::Pane* mpaExPanes[EXTRA_PLAYER_COUNT];
    };

    nw4r::lyt::TexMap* mpaTexMap[4 + EXTRA_PLAYER_COUNT];
    nw4r::lyt::Size maIconSize[4 + EXTRA_PLAYER_COUNT];

public:
    // -----------
    // Static Data
    // -----------

    static const long PLAYER_PANE_INDEX[];
    static const long PLAYER_PICTURE_INDEX[];
    static const long PLAYER_TEXTBOX_INDEX[];
    static const long PLAYER_BOTH_TEXTBOX_INDEX[][2];
};
