#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_base.h"
#include "d_system/d_fukidashiInfo.h"

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

    /**
     * VT+0x08 0x80157110
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x80157260
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x801571A0
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

    /**
     * VT+0x2C 0x80157210
     * do method for the draw operation.
     */
    PACK_RESULT_e draw() override;

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