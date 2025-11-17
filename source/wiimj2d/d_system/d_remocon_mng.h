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
    // Constants and Types
    // ^^^^^^

    static constexpr int CONNECT_COUNT = REMOCON_CONNECT_COUNT;

    class dConnect_c
    {
        SIZE_ASSERT(0x98);

        friend class dRemoconMng_c;

    public:
        // Constants and Types
        // ^^^^^^

        class dExtension_c
        {
            SIZE_ASSERT(0x48);

            /* 0x00 VTABLE 0x80319240 */

        public:
            // Constants and Types
            // ^^^^^^

            enum class Type_e {
                NONE = 0,
                FREESTYLE = 1,
                OTHER = 2,
                NOT_FOUND = 3,
            };

        public:
            // Virtual Functions
            // ^^^^^^

            /* 0x800DC360 */
            virtual ~dExtension_c();

        public:
            // Instance Methods
            // ^^^^^^

            /* 0x800DCFD0 */
            void shutdown();

            /* 0x800DCFF0 */
            void execute();

            inline mPad::CH_e getChannel() const
            {
                return mChannel;
            }

            inline Type_e getType() const
            {
                return mType;
            }

        private:
            // Instance Variables
            // ^^^^^^

            /* 0x04 */ mPad::CH_e mChannel;
            /* 0x08 */ Type_e mType;
            /* 0x0C */ sStateMgrDefault_c<dExtension_c> mStateMgr;
        };

        enum class PrimaryDev_e : u8 {
            CORE,
            EXTENSION,
        };

    public:
        // Structors
        // ^^^^^^

        /* 0x800DC660 */
        dConnect_c(mPad::CH_e channel);

    public:
        // Instance Methods
        // ^^^^^^

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

        inline EGG::CoreController* getCoreController() const
        {
            return mPad::g_core[static_cast<std::size_t>(mChannel)];
        }

        //
        // Button checks
        //

        /**
         * Check if the confirm (2 or A) button is pressed. Expects the caller to confirm the
         * controller is connected.
         */
        bool checkConfirm()
        {
            return getCoreController()->down(WPAD_BUTTON_2 | WPAD_BUTTON_A);
        }

        /**
         * Check if the cancel (1 or B) button is pressed. Expects the caller to confirm the
         * controller is connected.
         */
        bool checkCancel() const
        {
            return getCoreController()->down(WPAD_BUTTON_1 | WPAD_BUTTON_B);
        }

        /**
         * Check if left is pressed. Expects the caller to confirm the controller is connected.
         */
        inline bool checkLeft() const
        {
            return getCoreController()->down(WPAD_SIDE_BUTTON_LEFT);
        }

        /**
         * Check if right is pressed. Expects the caller to confirm the controller is connected.
         */
        inline bool checkRight() const
        {
            return getCoreController()->down(WPAD_SIDE_BUTTON_RIGHT);
        }

        /**
         * Check if up is pressed. Expects the caller to confirm the controller is connected.
         */
        inline bool checkUp() const
        {
            return getCoreController()->down(WPAD_SIDE_BUTTON_UP);
        }

        /**
         * Check if down is pressed. Expects the caller to confirm the controller is connected.
         */
        inline bool checkDown() const
        {
            return getCoreController()->down(WPAD_SIDE_BUTTON_DOWN);
        }

    private:
        // Instance Variables
        // ^^^^^^

        FILL(0x00, 0x04);

        /* 0x04 */ mPad::CH_e mChannel;
        /* 0x08 */ dExtension_c mExtension;
        /* 0x50 */ int mBattery;
        /* 0x54 */ bool mAllowConnect;
        /* 0x55 */ PrimaryDev_e mPrimaryDev;
        /* 0x58 */ int m0x58;
        /* 0x5C */ sStateMgrDefault_c<dConnect_c> mStateMgr;

    public:
        // Static Variables
        // ^^^^^^

        /* 0x80428280 */ static bool m_isBoot;

    public:
        // State IDs
        // ^^^^^^

        sState_Extern(0x80371B30, dRemoconMng_c::dConnect_c, Shutdown);
        sState_Extern(0x80371B70, dRemoconMng_c::dConnect_c, Setup);
    };

public:
    // Structors
    // ^^^^^^

    /* 0x800DC040 */
    dRemoconMng_c();

    dRemoconMng_c(dRemoconMng_c* old);

    /* 0x800DC0D0 */
    virtual ~dRemoconMng_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dConnect_c* mpaConnect[CONNECT_COUNT];

public:
    // Static Methods
    // ^^^^^^

    /* 0x800DC570 */
    static void execute();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A308 */
    static dRemoconMng_c* m_instance;
};
