#ifndef M3D_M_MDL_H
#define M3D_M_MDL_H

#include <machine/m3d/m_banm.h>
#include <machine/m3d/m_calc_ratio.h>
#include <machine/m3d/m_smdl.h>
#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_calcworld.h>
#include <nw4r/g3d/g3d_resmdl.h>

namespace m3d
{

class callback_c
{
public:
    virtual ~callback_c();
    virtual void timingA(u32, nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl);
    virtual void timingB(u32, nw4r::g3d::WorldMtxManip*, nw4r::g3d::ResMdl);
    virtual void timingC(nw4r::math::MTX34*, nw4r::g3d::ResMdl);
};

class mdl_c : public smdl_c
{
    SIZE_ASSERT(0x40);

public:
    class mdlCallback_c : public nw4r::g3d::ICalcWorldCallback
    {
        SIZE_ASSERT(0x34);

    public:
        mdlCallback_c();
        virtual ~mdlCallback_c();

        bool create(nw4r::g3d::ResMdl, mAllocator_c*, u32*);

        virtual void
        ExecCallbackA(nw4r::g3d::ChrAnmResult*, nw4r::g3d::ResMdl, nw4r::g3d::FuncObjCalcWorld*);
        virtual void
        ExecCallbackB(nw4r::g3d::WorldMtxManip*, nw4r::g3d::ResMdl, nw4r::g3d::FuncObjCalcWorld*);
        virtual void
        ExecCallbackC(nw4r::math::MTX34*, nw4r::g3d::ResMdl, nw4r::g3d::FuncObjCalcWorld*);

        void remove();
        void setBlendFrame(f32);
        void calcBlend();

        mAllocator_c* getAllocator()
        {
            return mpAlloc;
        }

        void setBaseCallback(callback_c* cb)
        {
            mpBaseCallback = cb;
        }

    private:
        /* 0x04 */ calcRatio_c mCalcRatio;
        /* 0x24 */ int mNumNode;
        /* 0x28 */ nw4r::g3d::ChrAnmResult* mpNodes;
        /* 0x2C */ callback_c* mpBaseCallback;
        /* 0x30 */ mAllocator_c* mpAlloc;
    };

    mdl_c();
    /* VT+0x08 */ virtual ~mdl_c();

    bool create(nw4r::g3d::ResMdl, mAllocator_c*, u32, int, u32*);
    bool create(nw4r::g3d::ResMdl, mdlCallback_c* cb, mAllocator_c*, u32, int, u32*);

    /* VT+0x10 */ virtual void remove();

    void setCallback(callback_c* cb);
    void play();
    void setAnm(banm_c&);
    void setAnm(banm_c&, f32);

private:
    /* 0x0C */ mdlCallback_c mCallback;
};

} // namespace m3d

#endif
