#pragma once

#include <dynamic/actor/static/d_a_player_manager.h>
#include <dynamic/d_base_actor.h>
#include <machine/m_vec.h>

class dActor_c : public dBaseActor_c
{
    SIZE_ASSERT(0x392);

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x60 0x80065080 */
    virtual bool ActorDrawCullCheck();

    /* VT+0x64 0x80065650 */
    virtual void block_hit_init();

    /* VT+0x68 0x8001D210 */
    virtual bool VT_0x68()
    {
        return true;
    }

    /* VT+0x6C 0x8001D200 */
    virtual u8* getPlrNo()
    {
        return &mPlayerNo;
    }

    /* VT+0x70 0x80065620 */
    virtual mVec3_c getLookatPos() const;

    /* VT+0x74 0x8001D1F0 */
    virtual bool isSpinLiftUpEnable()
    {
        return true;
    }

    /* VT+0x78 0x80065820 */
    virtual void setSpinLiftUpActor(dActor_c* actor);

    /* VT+0x7C 0x8001D1E0 */
    virtual void setCarryFall(dActor_c* actor, int param2)
    {
    }

    /* VT+0x80 0x80065830 */
    virtual void setEatTongue(dActor_c* actor);

    /* VT+0x84 0x80065850 */
    virtual void setEatTongueOff(dActor_c* actor);

    /* VT+0x88 0x80065860 */
    virtual void setEatMouth(dActor_c* actor);

    /* VT+0x8C 0x80065870 */
    virtual bool setEatSpitOut(dActor_c* actor);

    /* VT+0x90 0x80065880 */
    virtual bool setEatGlupDown(dActor_c* actor);

    /* VT+0x94 0x80065AC0 */
    virtual void eatMove(dActor_c* actor);

    /* VT+0x98 0x80066080 */
    virtual void removeCc();

    /* VT+0x9C 0x80066090 */
    virtual void reviveCc();

    /* VT+0xA0 0x80065950 */
    virtual void setAfterEatScale();

    /* VT+0xA4 0x80065970 */
    virtual void calcSpitOutPos(dActor_c* actor);

    /* VT+0xA8 0x80065A00 */
    virtual float calcEatScaleRate(dActor_c* yoshi);

    /* VT+0xAC 0x80065A40 */
    virtual void calcEatInScale(dActor_c* yoshi);

    /* VT+0xB0 0x80065660 */
    virtual bool allEnemyDeathEffSet();

    /* VT+0xB4 0x80065B40 */
    virtual void VT_0xB4();

    /* VT+0xB8 0x8001D1D0 */
    virtual void funsuiMoveX()
    {
    }

    /* VT+0xBC 0x80065B50 */
    virtual void cancelFunsuiActUpper();

    /* VT+0xC0 0x80065B60 */
    virtual void cancelFunsuiActSide();

    /* VT+0xC4 0x80065B70 */
    virtual void cancelFunsuiActVanish();

    /* VT+0xC8 0x80065CC0 */
    virtual void waterSplashEffect(const mVec3_c& position, float scale);

    /* VT+0xCC 0x80065DC0 */
    virtual void yoganSplashEffect(const mVec3_c& position, float scale);

    /* VT+0xD0 0x80065EC0 */
    virtual void poisonSplashEffect(const mVec3_c& position, float scale);

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800651C0 */
    void carryFukidashiCheck(int param1, mVec2_c param2);

    /* 0x80065480 */
    void carryFukidashiCancel(int param1, int param2);

    /* 0x80065520 */
    dAcPy_c* searchCarryFukidashiPlayer(int param1);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x125, 0x175);

    /* 0x175 */ u8 m0x175;
    /* 0x178 */ u32 m0x178;

    FILL(0x17C, 0x348);

    /* 0x348 */ u8 mDirection;

    FILL(0x349, 0x38C);

    /**
     * 0 = Default, 1 = Player, 2 = Yoshi, 3 = Enemy
     */
    /* 0x38C */ u8 mActorType;
    /* 0x38D */ u8 mPlayerNo;
    /* 0x38E */ u8 m0x38E;
    /* 0x38F */ u8 mLayer;
    /* 0x390 */ u8 m0x390;
    /* 0x391 */ u8 mOnBackFence;

public:
    // -----------
    // Static Data
    // -----------

    /* 0x80429FD8 */ static u8 mExecStopReq;

    /* 0x80429FDA */ static u8 mExecStop;
};