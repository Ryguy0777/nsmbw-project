#pragma once

#include <dynamic/actor/d_a_player_manager.h>
#include <dynamic/d_base.h>
#include <dynamic/d_fukidashiInfo.h>

class dfukidashiManager_c : public dBase_c
{
public:
    //
    // Constructors
    //

    /* 0x80157010 */
    dfukidashiManager_c();

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* 0x80157110 */
    int create() override;

    /* 0x801571A0 */
    int execute() override;

    /* 0x80157210 */
    int draw() override;

    /* 0x80157260 */
    int doDelete() override;

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x148);
    OFFSET_ASSERT(0x148);

    /* 0x148 */ dfukidashiInfo_c maInfo[PLAYER_COUNT];
};