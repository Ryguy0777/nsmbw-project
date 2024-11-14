#pragma once

#include "s_FStateMgr.h"
#include "s_StateStateMgr.h"

/**
 * A wrapper for sStateStateMgr_c that uses sFStateMgr_c.
 */
template <class T, class Method, class Method2>
class sFStateStateMgr_c : public sStateStateMgr_c<T, sFStateMgr_c, Method, Method2>
{
public:
    sFStateStateMgr_c(T& owner)
      : sStateStateMgr_c<T, sFStateMgr_c, Method, Method2>(owner)
    {
    }
};