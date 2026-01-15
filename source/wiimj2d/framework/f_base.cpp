// f_base.cpp
// NSMBW .text: 0x80161A60 - 0x80162C80

#include "f_base.h"

[[nsmbw(0x80161C10)]]
fBase_c::fBase_c();

[[nsmbw(0x80161D80)]]
fBase_c::~fBase_c();

[[nsmbw(0x80161EC0)]]
fBase_c::PACK_RESULT_e fBase_c::create();

[[nsmbw(0x80161ED0)]]
fBase_c::PACK_RESULT_e fBase_c::preCreate();

[[nsmbw(0x80161EE0)]]
void fBase_c::postCreate(MAIN_STATE_e state);

[[nsmbw(0x80161F70)]]
fBase_c::PACK_RESULT_e fBase_c::doDelete();

[[nsmbw(0x80162030)]]
fBase_c::PACK_RESULT_e fBase_c::preDelete();

[[nsmbw(0x801620A0)]]
void fBase_c::postDelete(MAIN_STATE_e state);

[[nsmbw(0x80162210)]]
fBase_c::PACK_RESULT_e fBase_c::execute();

[[nsmbw(0x80162220)]]
fBase_c::PACK_RESULT_e fBase_c::preExecute();

[[nsmbw(0x80162250)]]
void fBase_c::postExecute(MAIN_STATE_e state);

[[nsmbw(0x80162310)]]
fBase_c::PACK_RESULT_e fBase_c::draw();

[[nsmbw(0x80162320)]]
fBase_c::PACK_RESULT_e fBase_c::preDraw();

[[nsmbw(0x80162350)]]
void fBase_c::postDraw(MAIN_STATE_e state);

[[nsmbw(0x80162410)]]
void fBase_c::deleteReady();

[[nsmbw(0x80162650)]]
void fBase_c::deleteRequest();

[[nsmbw(0x80162730)]]
bool fBase_c::entryFrmHeap(u32 size, void* parentHeap);

[[nsmbw(0x80162930)]]
bool fBase_c::entryFrmHeapNonAdjust(u32 size, void* parentHeap);

[[nsmbw(0x801629F0)]]
bool fBase_c::createHeap();

[[nsmbw(0x80162A00)]]
void* fBase_c::operator new(size_t);

[[nsmbw(0x80162A60)]]
void fBase_c::operator delete(void*);

[[nsmbw(0x80162B60)]]
bool fBase_c::checkChildProcessCreateState() const;

[[nsmbw(0x80162C40)]]
fBase_c* fBase_c::createChild(fProfName profName, fBase_c* parent, u32 param, u8 groupType);

[[nsmbw(0x80162C60)]]
fBase_c* fBase_c::createRoot(fProfName profName, u32 param, u8 groupType);
