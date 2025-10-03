#pragma once

#include "state/s_FStateFct.h"
#include "state/s_StateInterfaces.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"

template<class T>
using sStateMgrDefault_c =
sStateMgr_c<T, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>;
