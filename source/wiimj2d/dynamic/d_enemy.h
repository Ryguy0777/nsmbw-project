#pragma once

#include "state/s_State.h"
#include <dynamic/d_actor.h>
#include <dynamic/d_actor_state.h>

class dCc_c;

class dEn_c : public dActorMultiState_c
{
    SIZE_ASSERT(0x524);

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /**
     * VT+0x24 0x80095240
     * pre method for the execute operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int preExecute() override;

    /* VT+0x8C 0x80097D30 */
    virtual bool setEatSpitOut(dActor_c* actor) override;

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80097B90 */
    void slipBound(dActor_c* actor);

    u8 setCollTimer(int player, u8 timer);
    u8 setCollTimer(dActor_c* player, u8 timer);

    u8 getCollTimer(int player) const;
    u8 getCollTimer(dActor_c* player) const;

    u8 incrementCollTimer(int player, int increment);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x414, 0x504);

    // Change from u16 to u8 to fit more players
    /* 0x504 */ u8 mCollTimer[8];

    FILL(0x50C, 0x524);

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x80095950 */
    static void normal_collcheck(dCc_c* object, dCc_c* other);

public:
    // ---------
    // State IDs
    // ---------

    sState_Extern(0x80358404, dEn_c, EatOut);
};