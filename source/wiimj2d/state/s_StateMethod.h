#pragma once

#include "s_StateInterfaces.h"

/**
 * A class that handles state execution and transition. [Presumably, sStateMethod_c actually means
 * "methods for state interaction", or something like that].
 */
class sStateMethod_c
{
public:
    /**
     * Constructs a new sStateMethod_c instance.
     * @param checker The state checker to use.
     * @param factory The state factory to use.
     * @param initialState The initial state ID of this instance.
     */
    sStateMethod_c(
      sStateIDChkIf_c& checker, sStateFctIf_c& factory, const sStateIDIf_c& initialState
    );

    /**
     * VT+0x08
     * Destroys the sStateMethod_c instance.
     */
    virtual ~sStateMethod_c();

    /**
     * VT+0x0C
     * Initializes the current state.
     */
    virtual void initializeStateMethod();

    /**
     * VT+0x10
     * Executes the current state.
     */
    virtual void executeStateMethod();

    /**
     * VT+0x14
     * Prepares the current state for termination.
     */
    virtual void finalizeStateMethod();

    /**
     * VT+0x18 0x8015FD50
     * Transitions to a new state ID.
     * @param newStateID The new state ID to transition to.
     */
    virtual void changeStateMethod(const sStateIDIf_c& newStateID);

    /**
     * VT+0x1C
     * Marks the current state to be executed again.
     */
    virtual void refreshStateMethod()
    {
        mRefreshStateMethod = true;
    }

    /**
     * VT+0x20
     * Returns the current state.
     */
    virtual sStateIf_c* getState() const
    {
        return mpState;
    }

    /**
     * VT+0x24
     * Returns the next state ID.
     */
    virtual const sStateIDIf_c* getNewStateID() const
    {
        return mpNewStateID;
    }

    /**
     * VT+0x28
     * Returns the current state ID.
     */
    virtual const sStateIDIf_c* getStateID() const
    {
        return mpStateID;
    }

    /**
     * VT+0x2C
     * Returns the previous state ID.
     */
    virtual const sStateIDIf_c* getOldStateID() const
    {
        return mpOldStateID;
    }

    /**
     * VT+0x30
     * Performs the actual state initialization.
     */
    virtual int initializeStateLocalMethod() = 0;

    /**
     * VT+0x34
     * Performs the actual state execution.
     */
    virtual void executeStateLocalMethod() = 0;

    /**
     * VT+0x38
     * Performs the actual state termination.
     */
    virtual void finalizeStateLocalMethod() = 0;

    /**
     * VT+0x3C
     * Performs the actual state transition.
     * @param newStateID The new state ID to transition to.
     */
    virtual void changeStateLocalMethod(const sStateIDIf_c& newStateID) = 0;

protected:
    /**
     * @unused The state checker to use.
     */
    /* 0x04 */ sStateIDChkIf_c& mpStateChk;

    /**
     * The state factory which produces the state holder.
     */
    /* 0x08 */ sStateFctIf_c& mpStateFct;

    /**
     * A lock to ensure ::initializeStateMethod and ::finalizeStateMethod are not called
     * recursively.
     */
    /* 0x0C */ bool mInitFinalizeLock;

    /**
     * A lock to ensure ::executeStateMethod is not called recursively.
     */
    /* 0x0D */ bool mExecutionLock;

    /**
     * If the state holder contains a valid state ID.
     */
    /* 0x0E */ bool mIsValid;

    /**
     * If the current state has changed during execution.
     */
    /* 0x0F */ bool mStateChanged;

    /**
     * True, if after a state transition, the state should be executed again.
     */
    /* 0x10 */ bool mRefreshStateMethod;

    /**
     * The next state ID.
     */
    /* 0x14 */ const sStateIDIf_c* mpNewStateID;

    /**
     * The previous state ID.
     */
    /* 0x18 */ const sStateIDIf_c* mpOldStateID;

    /**
     * The current state ID.
     */
    /* 0x1C */ const sStateIDIf_c* mpStateID;

    /**
     * The current state holder.
     */
    /* 0x20 */ sStateIf_c* mpState;
};