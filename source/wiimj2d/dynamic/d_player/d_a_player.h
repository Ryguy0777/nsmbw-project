#pragma once

#include <dynamic/d_a_player_base.h>
#include <dynamic/d_a_player_manager.h>

class dAcPy_c : public daPlBase_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x801275B0 */
    float getJumpSpeed();

    /* 0x8012E6E0 */
    bool releaseCarryActor();

    /* 0x80138FA0 */
    bool setBalloonInDamage();

    /* 0x8013D7B0 */
    void checkRest();

    /* 0x8013DA30 */
    void stopOtherDownDemo();

    /* 0x8013DB30 */
    void playOtherDownDemo();

    /* 0x80141020 */
    void initChangeInit();

    /* 0x80141080 */
    bool executeChangeInit();

    /* 0x80141080 */
    void setChange(int param);

    /* 0x80144C60 */
    void setSceneChangeInfo();

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /**
     * VT+0x08 0x80144EA0
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /* VT+0x28C 0x801400B0 */
    void executeDemoGoal_Run() override;

public:
    // -----------
    // Member Data
    // -----------

    /* 0x14D4 */ daPyMng_c::PlayerType_e mPlayerType;

    FILL(0x14D8, 0x14E0);

    /* 0x14E0 */ PLAYER_POWERUP_e mNextPowerup;

    FILL(0x14E4, 0x153C);

    /* 0x153C */ u8 mScrollType;

    FILL(0x153D, 0x1554);

    /* 0x1554 */ int m0x1554;
};