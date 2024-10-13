#pragma once

#include "s_FState.h"
#include "s_FStateFct.h"
#include "s_FStateID.h"
#include "s_StateMgr.h"

/**
 * A wrapper for sStateMgr_c that uses sFStateFct_c and sStateIDChk_c.
 * @tparam T The class that this state belongs to.
 * @tparam Method The method to use for the state manager.
 */
template <class T, class Method>
class sFStateMgr_c : public sStateMgr_c<T, Method, sFStateFct_c, sStateIDChk_c>
{
public:
    sFStateMgr_c(T& owner, const sStateIDIf_c& initializeState)
      : sStateMgr_c<T, Method, sFStateFct_c, sStateIDChk_c>(owner, initializeState)
    {
    }
};