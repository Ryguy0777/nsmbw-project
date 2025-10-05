#pragma once

#include "d_system/d_scene.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"

#include "d_en_boss/d_pregamelyt.h"

class dScCrsin_c : public dScene_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x8091EFD0 */
    virtual ~dScCrsin_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8091EC50 */
    int loadDefaultObjectResPhase();

    /* 0x8091F560 */
    bool isDoneLoading();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x074 */ sStateMgrDefault_c<dScCrsin_c> mStateMgr;
    /* 0x0B0 */ dPreGameLyt_c mPreGameLyt;

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x8042A494 */ static dScCrsin_c* m_instance;

public:
    // ---------
    // State IDs
    // ---------

    sState_Extern(0x809A1BA8, dScCrsin_c, initStageProc);
    sState_Extern(0x809A1BE8, dScCrsin_c, resWaitProc);
    sState_Extern(0x809A1C28, dScCrsin_c, loadCourseProc);
    sState_Extern(0x809A1C68, dScCrsin_c, initSoundProc);
    sState_Extern(0x809A1CA8, dScCrsin_c, initStageProc2);
    sState_Extern(0x809A1CE8, dScCrsin_c, resWaitProc2);
    sState_Extern(0x809A1D28, dScCrsin_c, createReplayHeapProc);
    sState_Extern(0x809A1D68, dScCrsin_c, replayResWaitProc);
    sState_Extern(0x809A1DA8, dScCrsin_c, effectResWaitProc);
    sState_Extern(0x809A1DE8, dScCrsin_c, DispEndCheck);
};
