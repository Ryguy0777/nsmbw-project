#pragma once

#include <dynamic/d_scene.h>
#include <state/s_FStateFct.h>
#include <state/s_State.h>
#include <state/s_StateMethodUsr_FI.h>
#include <state/s_StateMgr.h>

class dWiiStrap_c;
class dYesNoWindow_c;
class dSelectCursor_c;
class dControllerInformation_c;

class dScBoot_c : public dScene_c,
                  public sStateMgr_c<dScBoot_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
{
public:
    // ------------
    // Constructors
    // ------------

    dScBoot_c();

public:
    // -------------------
    // Constants and Types
    // -------------------

    enum class CODE_REGION_e {
        P1, // PAL revision 1
        P2, // PAL revision 2
        E1, // USA revision 1
        E2, // USA revision 2
        J1, // JPN revision 1
        J2, // JPN revision 2
        K, // KOR
        W, // TWN
        C, // CHN (Nvidia Shield TV release)
    };

public:
    // ---------
    // Functions
    // ---------

    int recreate();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A620 */ static dScBoot_c* m_instance;

    static CODE_REGION_e m_codeRegion;

public:
    // ----------------
    // Static Functions
    // ----------------
    static void initCodeRegion();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x0B0, 0x0F0);
    /* 0x0F0 */ dWiiStrap_c* mWiiStrap;
    /* 0x0F4 */ dYesNoWindow_c* mYesNoWindow;
    /* 0x0F8 */ dSelectCursor_c* mSelectCursor;
    /* 0x0FC */ dControllerInformation_c* mControllerInformation;

    // ---------
    // State IDs
    // ---------

    sState_Extern(0x80377708, dScBoot_c, ResetWait);

    sState_Extern(0x80377748, dScBoot_c, ResetFadeOut);

    sState_Extern(0x80377788, dScBoot_c, ResetFadeIn);

    sState_Extern(0x803777C8, dScBoot_c, FadeOutWait);

    sState_Extern(0x80377808, dScBoot_c, WiiStrapKeyWait);

    sState_Extern(0x80377848, dScBoot_c, WiiStrapDispEndWait);

    /*
     * executeState: 0x8015D010
     */
    sState_Extern(0x80377888, dScBoot_c, WiiStrapFadeOut);

    sState_Extern(0x803778C8, dScBoot_c, ControllerInformationFadeIn);

    sState_Extern(0x80377908, dScBoot_c, ControllerInformationSoundWait);

    sState_Extern(0x80377948, dScBoot_c, ControllerInformationKeyWait);

    sState_Extern(0x80377988, dScBoot_c, ControllerInformationDispEndWait);

    sState_Extern(0x803779C8, dScBoot_c, NandCommandEndWait);

    sState_Extern(0x80377A08, dScBoot_c, ExistFileCheck);

    sState_Extern(0x80377A48, dScBoot_c, NandSpaceCheck);

    sState_Extern(0x80377A88, dScBoot_c, CreateFile);

    sState_Extern(0x80377AC8, dScBoot_c, Load);

    sState_Extern(0x80377B08, dScBoot_c, GoToErrorFadeOut);

    sState_Extern(0x80377B48, dScBoot_c, GoToErrorFadeIn);

    sState_Extern(0x80377B88, dScBoot_c, NewSaveFileDisp);

    sState_Extern(0x80377BC8, dScBoot_c, ButtonInputWait);

    sState_Extern(0x80377C08, dScBoot_c, WindowExitWait);

    sState_Extern(0x80377C48, dScBoot_c, ProcEnd);

    sState_Extern(0x80377C88, dScBoot_c, ErrorWindowOnStageWait);

    sState_Extern(0x80377CC8, dScBoot_c, ErrorInfinityDisp);
};