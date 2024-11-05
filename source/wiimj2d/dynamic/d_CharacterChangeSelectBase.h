#pragma once

#include <dynamic/d_base.h>
#include <dynamic/d_player_model_manager.h>
#include <state/s_State.h>

class dCharacterChangeSelectContents_c;

class dCharacterChangeSelectBase_c : public dBase_c
{
public:
    //
    // Constants and Types
    //
#define CHARACTER_LIST_COUNT 5
    static constexpr dPyMdlMng_c::ModelType_e CHARACTER_FROM_BASE[] = {
      dPyMdlMng_c::ModelType_e::MODEL_MARIO,       dPyMdlMng_c::ModelType_e::MODEL_LUIGI,
      dPyMdlMng_c::ModelType_e::MODEL_YELLOW_TOAD, dPyMdlMng_c::ModelType_e::MODEL_BLUE_TOAD,
      dPyMdlMng_c::ModelType_e::MODEL_TOADETTE,
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
    };

    static constexpr Icon_e ICON_FROM_BASE[] = {
      Icon_e::ICON_MARIO,     Icon_e::ICON_LUIGI,    Icon_e::ICON_YELLOW_TOAD,
      Icon_e::ICON_BLUE_TOAD, Icon_e::ICON_TOADETTE,
    };

    static constexpr Icon_e ICON_LOCKED_FROM_BASE[] = {
      Icon_e::ICON_MARIO_LOCKED,     Icon_e::ICON_LUIGI_LOCKED,    Icon_e::ICON_YELLOW_TOAD_LOCKED,
      Icon_e::ICON_BLUE_TOAD_LOCKED, Icon_e::ICON_TOADETTE_LOCKED,
    };

    //
    // Functions
    //

    /* 0x8076FAE0 */
    bool updateRemocon();

    /* 0x8076FC80 */
    bool isCharacterLocked(dPyMdlMng_c::ModelType_e character);

    /* 0x8076FD70 */
    void UNDEF_8076FD70(u32 swapIndex, u32 baseIndex);

    /* 0x8076FE40 */
    void UNDEF_8076FE40();

    /* 0x8076FEE0 */
    void UNDEF_8076FEE0();

    //
    // Member Data
    //

    FILL(0x070, 0x074);

    /* 0x074 */ dCharacterChangeSelectContents_c* mpCcSelContents;

    FILL(0x078, 0x07C);

    /* 0x07C */ u32* m0x07C;

    FILL(0x080, 0x29A);

    /* 0x29A */ bool mDecided;

    FILL(0x29B, 0x2D4);

    /* 0x2D4 */ dPyMdlMng_c::ModelType_e mDecidedCharacter;
    /* 0x2D8 */ u32 mSelectedCharacter;
    /* 0x2DC */ u32 m0x2DC;
    /* 0x2E0 */ u32 mSelectedBaseIndex;

    //
    // State IDs
    //

    sState_Extern(0x80990958, dCharacterChangeSelectBase_c, initial);
    sState_Extern(0x80990998, dCharacterChangeSelectBase_c, OnStageWait);
    sState_Extern(0x809909D8, dCharacterChangeSelectBase_c, OnStageAnimeEndWait);
    sState_Extern(0x80990A18, dCharacterChangeSelectBase_c, ConnectWait);
    sState_Extern(0x80990A58, dCharacterChangeSelectBase_c, SelectStartWait);
    sState_Extern(0x80990A98, dCharacterChangeSelectBase_c, ButtonExitAnimeEndWait);
    sState_Extern(0x80990AD8, dCharacterChangeSelectBase_c, ButtonOnStageAnimeEndWait);
    sState_Extern(0x80990B18, dCharacterChangeSelectBase_c, ArrowDispWait);
    sState_Extern(0x80990B58, dCharacterChangeSelectBase_c, SelectWait);
    sState_Extern(0x80990B98, dCharacterChangeSelectBase_c, MoveAnimeStartWait);
    sState_Extern(0x80990BD8, dCharacterChangeSelectBase_c, MoveAnimeEndWait);
    sState_Extern(0x80990C18, dCharacterChangeSelectBase_c, HitAnimeEndWait);
    sState_Extern(0x80990C58, dCharacterChangeSelectBase_c, HitAfterExitWait);
    sState_Extern(0x80990C98, dCharacterChangeSelectBase_c, ExitAnimeEndForPlayerOnStageWait);
    sState_Extern(0x80990CD8, dCharacterChangeSelectBase_c, PlayerOnStageWait);
    sState_Extern(0x80990D18, dCharacterChangeSelectBase_c, PlayerDisp);
    sState_Extern(0x80990D58, dCharacterChangeSelectBase_c, PlayerExitWait);
    sState_Extern(0x80990D98, dCharacterChangeSelectBase_c, PlayerExitEndClearWaKu);
    sState_Extern(
      // This one is so LONG!!!
      0x80990DD8, dCharacterChangeSelectBase_c, ConnectCutEnterWaitWindowOnStageAnimeEndWait
    );
    sState_Extern(0x80990E18, dCharacterChangeSelectBase_c, ExitAnimeEndWait);
};