#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_base.h>
#include <dynamic/d_fukidashiInfo.h>

class dfukidashiManager_c : public dBase_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x80157010 */
    dfukidashiManager_c();

    /* VT+0x48 0x80157080 */
    ~dfukidashiManager_c() override;

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
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80157360 */
    void FUN_80157360(int param1, int param2, int param3);

    /* 0x80157450 */
    void FUN_80157450(int param1, int param2);

    /* 0x801574A0 */
    void FUN_801574A0(int param1, int param2);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x148);
    OFFSET_ASSERT(0x148);

    /* 0x148 */ dfukidashiInfo_c maInfo[PLAYER_COUNT];

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A600 */
    static dfukidashiManager_c* m_instance;
};