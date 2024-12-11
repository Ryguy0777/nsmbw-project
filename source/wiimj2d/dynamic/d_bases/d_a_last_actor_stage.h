#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_base.h>

class daLastActorStage_c : public dBase_c
{
public:
    // ------------
    // Constructors
    // ------------

    daLastActorStage_c() = default;

    virtual ~daLastActorStage_c() override = default;

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x08 0x808306E0 */
    int create() override;

    /* VT+0x14 0x80830710 */
    int doDelete() override;

    /* VT+0x20 0x80830720 */
    int execute() override;

    /* VT+0x2C 0x80830BB0 */
    int draw() override;

public:
    // -----------
    // Member Data
    // -----------

    // Original class
    // /* 0x70 */ u32 mBtnPressed[4];
    // /* 0x80 */ bool mIsShaking[4];
    // OFFSET_ASSERT(0x84);

    u32 mBtnPressed[PLAYER_COUNT];
    bool mIsShaking[PLAYER_COUNT];
};