#pragma once

#include "d_system/d_a_player_base.h"
#include "d_system/d_player_model_manager.h"

class daYoshi_c : public daPlBase_c
{
public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x0DC 0x80150E10 */
    virtual void executeLastAll() override;

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80150420 */
    void setHitTongueReserve();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x14D4 */ dPyMdlMng_c mModelMng;
};