#pragma once

#include "s_StateMethod.h"

/**
 * An extension to sStateMethod_c that implements the remaining abstract methods. [Name might mean
 * "Functionality implementation"].
 */
class sStateMethodUsr_FI_c : public sStateMethod_c
{
public:
    sStateMethodUsr_FI_c(
      sStateIDChkIf_c& checker, sStateFctIf_c& factory, const sStateIDIf_c& initialState
    );

    /* VT+0x08 */
    virtual ~sStateMethodUsr_FI_c() override;

    /**
     * VT+0x30
     * Performs the actual state initialization.
     */
    virtual int initializeStateLocalMethod() override;

    /**
     * VT+0x34
     * Performs the actual state execution.
     */
    virtual void executeStateLocalMethod() override;

    /**
     * VT+0x38
     * Performs the actual state termination.
     */
    virtual void finalizeStateLocalMethod() override;

    /**
     * VT+0x3C
     * Performs the actual state transition.
     * @param newStateID The new state ID to transition to.
     */
    virtual void changeStateLocalMethod(const sStateIDIf_c& newStateID) override;
};