#pragma once

#include <dynamic/d_scene.h>
#include <state/s_FStateFct.h>
#include <state/s_State.h>
#include <state/s_StateMethodUsr_FI.h>
#include <state/s_StateMgr.h>

class dScCrsin_c : public dScene_c,
                   public sStateMgr_c<dScCrsin_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
{
public:
    /* 0x8091EC50 */
    static int loadDefaultObjectResPhase();

    /* 0x8091F560 */
    bool isDoneLoading();

    //
    // State IDs
    //

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

// dScCrsin_c::executeState_resWaitProc2
// 0x8091fe20