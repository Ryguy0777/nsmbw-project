#pragma once

#include "d_system/d_game_key.h"
#include "machine/m_pad.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"
#include <egg/core/eggHeap.h>

#define REMOCON_CONNECT_COUNT 8

class dRemoconMng_c
{
    SIZE_ASSERT(0x4 + REMOCON_CONNECT_COUNT * 0x4);

public:
    // -------------------
    // Constants and Types
    // -------------------

    static constexpr int CONNECT_COUNT = REMOCON_CONNECT_COUNT;

    class dConnect_c
    {
        SIZE_ASSERT(0x98);

        friend class dRemoconMng_c;

    public:
        // -------------------
        // Constants and Types
        // -------------------

        class dExtension_c
        {
        public:
            // ----------------
            // Member Functions
            // ----------------

            /* 0x800DCFD0 */
            void shutdown();

            /* 0x800DCFF0 */
            void execute();
        };

        enum class PrimaryDev_e : u8 {
            CORE,
            EXTENSION,
        };

    public:
        // ------------
        // Constructors
        // ------------

        /* 0x800DC660 */
        dConnect_c(mPad::CH_e channel);

    public:
        // ----------------
        // Member Functions
        // ----------------

        /* 0x800DCA60 */
        void execute();

        /* 0x800DCA80 */
        void onRumbleEnable();

        inline bool splitExtension()
        {
            return false;
        }

        inline bool isSetup() const
        {
            return mStateMgr.getStateID()->isEqual(StateID_Setup);
        }

        inline mPad::CH_e getChannel() const
        {
            return mChannel;
        }

        inline dExtension_c* getExtension()
        {
            return &mExtension;
        }

        inline int getBattery() const
        {
            return mBattery;
        }

        inline bool getAllowConnect() const
        {
            return mAllowConnect;
        }

        inline bool setAllowConnect(bool set)
        {
            return mAllowConnect = set;
        }

        inline PrimaryDev_e getPrimaryDev() const
        {
            return mPrimaryDev;
        }

    private:
        // -----------
        // Member Data
        // -----------

        FILL(0x00, 0x04);

        /* 0x04 */ mPad::CH_e mChannel;
        /* 0x08 */ dExtension_c mExtension;

        FILL(0x09, 0x50);

        /* 0x50 */ int mBattery;
        /* 0x54 */ bool mAllowConnect;
        /* 0x55 */ PrimaryDev_e mPrimaryDev;
        /* 0x58 */ int m0x58;
        /* 0x5C */ sStateMgrDefault_c<dConnect_c> mStateMgr;

    public:
        // -----------
        // Static Data
        // -----------

        /* 0x80428280 */ static bool m_isBoot;

    public:
        // ---------
        // State IDs
        // ---------

        sState_Extern(0x80371B30, dRemoconMng_c::dConnect_c, Shutdown);
        sState_Extern(0x80371B70, dRemoconMng_c::dConnect_c, Setup);
    };

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800DC040 */
    dRemoconMng_c();

    dRemoconMng_c(dRemoconMng_c* old);

    /* 0x800DC0D0 */
    virtual ~dRemoconMng_c();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x04 */ dConnect_c* mpaConnect[CONNECT_COUNT];

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x800DC570 */
    static void execute();

    static void recreate(EGG::Heap* heap);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A308 */
    static dRemoconMng_c* m_instance;
};
