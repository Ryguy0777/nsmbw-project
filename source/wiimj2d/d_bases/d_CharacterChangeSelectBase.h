#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_player_model_manager.h"
#include "state/s_State.h"

class dCharacterChangeSelectContents_c;
class da2DPlayer_c;

class dCharacterChangeSelectBase_c : public dBase_c
{
public:
    // -------------------
    // Constants and Types
    // -------------------

#define CHARACTER_LIST_COUNT 8
    static constexpr PLAYER_TYPE_e CHARACTER_FROM_BASE[] = {
      PLAYER_TYPE_e::MARIO,       PLAYER_TYPE_e::LUIGI,      PLAYER_TYPE_e::YELLOW_TOAD,
      PLAYER_TYPE_e::BLUE_TOAD,   PLAYER_TYPE_e::TOADETTE,   PLAYER_TYPE_e::PURPLE_TOADETTE,
      PLAYER_TYPE_e::ORANGE_TOAD, PLAYER_TYPE_e::BLACK_TOAD,
    };

    enum class Icon_e {
        // Reserved
        ICON_NONE = 6,

        ICON_BLUE_TOAD = 0,
        ICON_BLUE_TOAD_LOCKED = 3,
        ICON_YELLOW_TOAD = 1,
        ICON_YELLOW_TOAD_LOCKED = 4,
        ICON_LUIGI = 2,
        ICON_LUIGI_LOCKED = 5,
        ICON_MARIO = 7,
        ICON_MARIO_LOCKED = 8,
        ICON_TOADETTE = 9,
        ICON_TOADETTE_LOCKED = 10,
        ICON_PURPLE_TOADETTE = 11,
        ICON_PURPLE_TOADETTE_LOCKED = 12,
        ICON_ORANGE_TOAD = 13,
        ICON_ORANGE_TOAD_LOCKED = 14,
        ICON_BLACK_TOAD = 15,
        ICON_BLACK_TOAD_LOCKED = 16,
    };

    static constexpr Icon_e ICON_FROM_BASE[] = {
      Icon_e::ICON_MARIO,       Icon_e::ICON_LUIGI,      Icon_e::ICON_YELLOW_TOAD,
      Icon_e::ICON_BLUE_TOAD,   Icon_e::ICON_TOADETTE,   Icon_e::ICON_PURPLE_TOADETTE,
      Icon_e::ICON_ORANGE_TOAD, Icon_e::ICON_BLACK_TOAD,
    };

    static constexpr Icon_e ICON_LOCKED_FROM_BASE[] = {
      Icon_e::ICON_MARIO_LOCKED,       Icon_e::ICON_LUIGI_LOCKED,
      Icon_e::ICON_YELLOW_TOAD_LOCKED, Icon_e::ICON_BLUE_TOAD_LOCKED,
      Icon_e::ICON_TOADETTE_LOCKED,    Icon_e::ICON_PURPLE_TOADETTE_LOCKED,
      Icon_e::ICON_ORANGE_TOAD_LOCKED, Icon_e::ICON_BLACK_TOAD_LOCKED,
    };

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8076FAE0 */
    bool updateRemocon();

    /* 0x8076FC80 */
    bool isCharacterLocked(PLAYER_TYPE_e character);

    /* 0x8076FD70 */
    void UNDEF_8076FD70(u32 swapIndex, u32 baseIndex);

    /* 0x8076FE40 */
    void UNDEF_8076FE40();

    /* 0x8076FEE0 */
    void UNDEF_8076FEE0();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x074);

    /* 0x074 */ dCharacterChangeSelectContents_c* mpCcSelContents;

    FILL(0x078, 0x07C);

    /* 0x07C */ u32* m0x07C;
    /* 0x080 */ // da2DPlayer_c* mpa2DPlayer_Removed[4];
    /* 0x080 */ da2DPlayer_c** mpa2DPlayer;

    FILL(0x084, 0x090);

    /* 0x090 */ LytBase_c mLayout;

    FILL(0x228, 0x296);

    /* 0x296 */ bool m0x296;
    /* 0x297 */ u8 m0x297;
    /* 0x298 */ u8 m0x298;

    FILL(0x299, 0x29A);

    /* 0x29A */ bool mDecided;
    /* 0x29B */ u8 m0x29B;
    /* 0x29C */ u8 m0x29C;

    FILL(0x29D, 0x2D4);

    /* 0x2D4 */ PLAYER_TYPE_e mDecidedCharacter;
    /* 0x2D8 */ int mPlayerNo;
    /* 0x2DC */ u32 m0x2DC;
    /* 0x2E0 */ u32 mSelectedBaseIndex;

    FILL(0x2E4, 0x2F0);

    /* 0x2F0 */ float mBaseY;

    OFFSET_ASSERT(0x2F4);

public:
    // ---------
    // State IDs
    // ---------

    /*
     * initializeState: 0x8076FFF0
     * executeState:    0x80770030
     * finalizeState:   0x80770050
     */
    sState_Extern(0x80990958, dCharacterChangeSelectBase_c, initial);

    /*
     * initializeState: 0x80770060
     * executeState:    0x80770070
     * finalizeState:   0x80770090
     */
    sState_Extern(0x80990998, dCharacterChangeSelectBase_c, OnStageWait);

    /*
     * initializeState: 0x807701F0
     * executeState:    0x807702A0
     * finalizeState:   0x807703F0
     */
    sState_Extern(0x809909D8, dCharacterChangeSelectBase_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x80770400
     * executeState:    0x80770430
     * finalizeState:   0x80770540
     */
    sState_Extern(0x80990A18, dCharacterChangeSelectBase_c, ConnectWait);

    /*
     * initializeState: 0x80770550
     * executeState:    0x80770560
     * finalizeState:   0x80770620
     */
    sState_Extern(0x80990A58, dCharacterChangeSelectBase_c, SelectStartWait);

    /*
     * initializeState: 0x80770630
     * executeState:    0x80770670
     * finalizeState:   0x807706D0
     */
    sState_Extern(0x80990A98, dCharacterChangeSelectBase_c, ButtonExitAnimeEndWait);

    /*
     * initializeState: 0x807706E0
     * executeState:    0x80770790
     * finalizeState:   0x80770820
     */
    sState_Extern(0x80990AD8, dCharacterChangeSelectBase_c, ButtonOnStageAnimeEndWait);

    /*
     * initializeState: 0x80770830
     * executeState:    0x80770850
     * finalizeState:   0x807708B0
     */
    sState_Extern(0x80990B18, dCharacterChangeSelectBase_c, ArrowDispWait);

    /*
     * initializeState: 0x807708D0
     * executeState:    0x807708E0
     * finalizeState:   0x80770B40
     */
    sState_Extern(0x80990B58, dCharacterChangeSelectBase_c, SelectWait);

    /*
     * initializeState: 0x80770B50
     * executeState:    0x80770BA0
     * finalizeState:   0x80770BE0
     */
    sState_Extern(0x80990B98, dCharacterChangeSelectBase_c, MoveAnimeStartWait);

    /*
     * initializeState: 0x80770BF0
     * executeState:    0x80770C90
     * finalizeState:   0x80770D00
     */
    sState_Extern(0x80990BD8, dCharacterChangeSelectBase_c, MoveAnimeEndWait);

    /*
     * initializeState: 0x80770D80
     * executeState:    0x80770E20
     * finalizeState:   0x80770E70
     */
    sState_Extern(0x80990C18, dCharacterChangeSelectBase_c, HitAnimeEndWait);

    /*
     * initializeState: 0x80770E80
     * executeState:    0x80770E90
     * finalizeState:   0x80770ED0
     */
    sState_Extern(0x80990C58, dCharacterChangeSelectBase_c, HitAfterExitWait);

    /*
     * initializeState: 0x80770EE0
     * executeState:    0x80771010
     * finalizeState:   0x80771070
     */
    sState_Extern(0x80990C98, dCharacterChangeSelectBase_c, ExitAnimeEndForPlayerOnStageWait);

    /*
     * initializeState: 0x80771090
     * executeState:    0x80771220
     * finalizeState:   0x80771270
     */
    sState_Extern(0x80990CD8, dCharacterChangeSelectBase_c, PlayerOnStageWait);

    /*
     * initializeState: 0x807712B0
     * executeState:    0x807712E0
     * finalizeState:   0x807713D0
     */
    sState_Extern(0x80990D18, dCharacterChangeSelectBase_c, PlayerDisp);

    /*
     * initializeState: 0x807713E0
     * executeState:    0x80771470
     * finalizeState:   0x807714C0
     */
    sState_Extern(0x80990D58, dCharacterChangeSelectBase_c, PlayerExitWait);

    /*
     * initializeState: 0x80771530
     * executeState:    0x807715B0
     * finalizeState:   0x80771610
     */
    sState_Extern(0x80990D98, dCharacterChangeSelectBase_c, PlayerExitEndClearWaKu);

    /*
     * initializeState: 0x80771620
     * executeState:    0x80771710
     * finalizeState:   0x807717A0
     */
    sState_Extern(
      0x80990DD8, dCharacterChangeSelectBase_c, ConnectCutEnterWaitWindowOnStageAnimeEndWait
    );

    /*
     * initializeState: 0x807717B0
     * executeState:    0x807717F0
     * finalizeState:   0x80771850
     */
    sState_Extern(0x80990E18, dCharacterChangeSelectBase_c, ExitAnimeEndWait);
};
