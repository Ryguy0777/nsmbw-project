#pragma once

#include <egg/core/eggDisposer.h>
#include <egg/math/eggMatrix.h>
#include <egg/math/eggVector.h>
#include <egg/prim/eggBitFlag.h>
#include <egg/prim/eggBuffer.h>
#include <revolution/kpad.h>
#include <revolution/wpad.h>

struct PADStatus;

namespace EGG
{

enum class eCoreDevType {
    GCN = 30,
    NONE = static_cast<int>(WPADDeviceType::WPAD_DEV_NONE),
};

constexpr int CORE_COUNT = 8;

constexpr WPADChannel GC_CHANNEL_BEGIN = static_cast<WPADChannel>(4);
constexpr WPADChannel GC_CHANNEL_END = static_cast<WPADChannel>(8);

class CoreStatus : public KPADStatus
{
public:
    //
    // Functions
    //

    /* 0x802BC9E0 */
    u32 getFSStickButton() const;

    /* 0x802BC9D0 */
    void init()
    {
        *this = {};
    }

    f32 getFSStickX() const
    {
        return fsStick.x;
    }

    f32 getFSStickY() const
    {
        return fsStick.y;
    }

    bool down(u32 mask) const
    {
        return (mask & hold);
    }

    bool up(u32 mask) const
    {
        return (mask & hold) != mask;
    }

    bool downTrigger(u32 mask) const
    {
        return (mask & trigger);
    }

    bool upTrigger(u32 mask) const
    {
        return (mask & release);
    }

    bool downAll(u32 mask) const
    {
        return (mask & hold) == mask;
    }

    bool upAll(u32 mask) const
    {
        return (mask & hold) == 0;
    }

    WPADDeviceType getDevType() const
    {
        return extensionType;
    }

    bool isCore() const
    {
        return getDevType() == WPADDeviceType::WPAD_DEV_CORE;
    }

    bool isFreestyle() const
    {
        return getDevType() == WPADDeviceType::WPAD_DEV_FS;
    }

    u32 getHold() const
    {
        return hold;
    }

    s8 getDpdValidFlag() const
    {
        return dpdPosValid;
    };

    Vector2f getAccelVertical()
    {
        return Vector2f(accVertical.x, accVertical.y);
    }

    const KPADVec3D& getAccel() const
    {
        return acc;
    }
};

class ControllerRumbleMgr;

class CoreController
{
    SIZE_ASSERT(0xBD0);

public:
    // ------------
    // Constructors
    // ------------

    /* 0x802BCA90 */
    CoreController();

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x08 */
    virtual void setPosParam(f32 v1, f32 v2);

    /* VT+0x0C */
    virtual void setHoriParam(f32 v1, f32 v2);

    /* VT+0x10 */
    virtual void setDistParam(f32 v1, f32 v2);

    /* VT+0x14 */
    virtual void setAccParam(f32 v1, f32 v2);

    /* VT+0x18 */
    virtual bool down(u32 mask) const;

    /* VT+0x1C */
    virtual bool up(u32 mask) const;

    /* VT+0x20 */
    virtual bool downTrigger(u32 mask) const;

    /* VT+0x24 */
    virtual bool upTrigger(u32 mask) const;

    /* VT+0x28 */
    virtual bool downAll(u32 mask) const;

    /* VT+0x2C */
    virtual bool upAll(u32 mask) const;

    /* VT+0x30 0x802BD0D0 */
    virtual void beginFrame(PADStatus* padStatus);

    /* VT+0x34 */
    virtual void endFrame();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x802BCAF0 */
    void sceneReset();

    /* 0x802BCBB0 */
    Vector2f getDpdRawPos();

    /* 0x802BCBF0 */
    void startMotor();

    /* 0x802BCC00 */
    void stopMotor();

    /* 0x802BCC10 */
    void createRumbleMgr(u8 numUnits);

    /* 0x802BCC70 */
    void startPatternRumble(const char* pattern, int duration, bool bGrabActive);

    /* 0x802BCC90 */
    void startPowerFrameRumble(float param1, int duration, bool bGrabActive);

    /* 0x802BCCB0 */
    void stopRumbleMgr();

    /* 0x802BCCD0 */
    void calc_posture_matrix(Matrix34f& posture, bool checkStable);

    void padToCoreStatus(PADStatus* padStatus);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x004 */ WPADChannel mChannel;
    /* 0x008 */ u32 mHeld;
    /* 0x00C */ u32 mTriggered;
    /* 0x010 */ u32 mReleased;
    /* 0x014 */ u32 m0x14;
    /* 0x018 */ CoreStatus maStatus[16];
    /* 0xB18 */ int mReadStatusIdx;
    /* 0xB1C */ TBitFlag<u8> mFlag;
    /* 0xB20 */ Vector3f mAccel;
    /* 0xB2C */ Vector2f mDpdPos;
    /* 0xB34 */ u32 mIdleTime;
    /* 0xB38 */ u32 mMotorPattern;
    /* 0xB3C */ bool mEnableMotor;
    /* 0xB40 */ s32 mMotorFrameDuration;
    /* 0xB44 */ u8 mMotorPatternLength;
    /* 0xB45 */ u8 mMotorPatternPos;
    /* 0xB48 */ ControllerRumbleMgr* mRumbleMgr;
    /* 0xB4C */ Matrix34f mPostureMatrix;
    /* 0xB7C */ Matrix34f mPostureMatrixPrev;
    /* 0xBAC */ TBitFlag<u8> mAccelFlags;
    /* 0xBB0 */ s32 mMaxAccelFrameTime;
    /* 0xBB4 */ s32 mAccelFrameTime[3];
    /* 0xBC0 */ f32 mMaxAccelDiff;
    /* 0xBC4 */ Vector3f mPrevAccel;
};

class CoreControllerMgr
{
    SIZE_ASSERT(0xE60);

    /* 0x0010 VTABLE */

public:
    // -------------------
    // Constants and Types
    // -------------------

    struct T__Disposer : Disposer {
        /* VT+0x08 */
        virtual ~T__Disposer();

        /* 0x8042B154 */ static T__Disposer* sStaticDisposer;
    };

    // This gets defined before the vtable
    /* 0x000 */ T__Disposer mDisposer;

public:
    // ------------
    // Constructors
    // ------------

    /* 0x802BD790 */
    CoreControllerMgr();

public:
    // ----------------
    // Static Functions
    // ----------------

    static void recreateInstance();

    static bool isGameCubeChannel(WPADChannel chan)
    {
        return chan >= GC_CHANNEL_BEGIN && chan < GC_CHANNEL_END;
    }

    static PADStatus* getPadStatus(WPADChannel chan);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042B150 */ static CoreControllerMgr* sInstance;

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x08 0x802BDBB0 */
    virtual void beginFrame();

    /* VT+0x0C 0x802BDC60 */
    virtual void endFrame();

public:
    // ---------
    // Functions
    // ---------

    [[address(0x802BD660)]]
    CoreController* getNthController(int n);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x014 */ TBuffer<CoreController*> mControllers;
    FILL(0x020, 0xE24);
    /* 0xE24 */ TBuffer<eCoreDevType> mDevTypes;
    FILL(0xE30, 0xE60);
};

class ControllerRumbleMgr
{
public:
    /* 0x802BE150 */
    void calc();
};

} // namespace EGG