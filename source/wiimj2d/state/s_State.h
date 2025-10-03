#pragma once

#include "s_FStateID.h"

#define sState(_class, _name)                                                                      \
    void executeState_##_name();                                                                   \
    void initializeState_##_name();                                                                \
    void finalizeState_##_name();                                                                  \
    static const sFStateID_c<_class> StateID_##_name

#define sState_Virtual(_class, _name)                                                              \
    virtual void executeState_##_name();                                                           \
    virtual void initializeState_##_name();                                                        \
    virtual void finalizeState_##_name();                                                          \
    static const sFStateID_c<_class> StateID_##_name

#define sState_Define(_class, _name)                                                               \
    const sFStateID_c<_class> _class::StateID_##_name(                                             \
      #_class "::StateID_" #_name, &_class::initializeState_##_name,                               \
      &_class::executeState_##_name, &_class::finalizeState_##_name                                \
    )

#define sState_Extern(_address, _class, _name)                                                     \
    void executeState_##_name();                                                                   \
    void initializeState_##_name();                                                                \
    void finalizeState_##_name();                                                                  \
    static const sFStateID_c<_class> StateID_##_name asm("ext_" #_address)

#define sState_ExternVirtual(_address, _class, _name)                                              \
    virtual void executeState_##_name();                                                           \
    virtual void initializeState_##_name();                                                        \
    virtual void finalizeState_##_name();                                                          \
    static const sFStateID_c<_class> StateID_##_name asm("ext_" #_address)
