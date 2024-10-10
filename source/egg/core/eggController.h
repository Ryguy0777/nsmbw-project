#pragma once

namespace EGG
{

struct PADStatus;

class CoreController
{
public:
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

    /* VT+0x30 */
    virtual void beginFrame(PADStatus* padStatus);

    /* VT+0x34 */
    virtual void endFrame();
};

} // namespace EGG