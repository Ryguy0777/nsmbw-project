// m_pad.cpp
// NSMBW .text: 0x8016F330 - 0x8016F880

#include "m_pad.h"

#include <PatchRel.h>
#include <egg/core/eggController.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>

namespace mPad
{

/* 0x80377F88 */
EGG::CoreController* g_core[PAD_CHAN_COUNT];

[[address_data(0x8042A740)]]
EGG::CoreControllerMgr* g_padMg;

[[address_data(0x8042A744)]]
CH_e g_currentCoreID;

[[address_data(0x8042A748)]]
EGG::CoreController* g_currentCore;

[[address_data(0x8042A74C)]]
bool g_IsConnected[PAD_CHAN_COUNT];

[[address_data(0x8042A750)]]
u32 g_PadFrame;

/* 0x8042A754 */
bool s_WPADInfoAvailable[PAD_CHAN_COUNT];

[[address_data(0x8042A758)]]
s32 s_GetWPADInfoInterval;

[[address_data(0x8042A75C)]]
s32 s_GetWPADInfoCount;

/* 0x80377FA8 */
float g_PadAdditionalData[PAD_CHAN_COUNT][6];

/* 0x80378008 */
WPADInfo s_WPADInfo[PAD_CHAN_COUNT];

/* 0x80378068 */
WPADInfo s_WPADInfoTmp[PAD_CHAN_COUNT];

[[address(0x8042A754)]]
bool s_WPADInfoAvailableOld[4];

[[address(0x80377FA8)]]
float g_PadAdditionalDataOld[4][6];

[[address(0x80378008)]]
WPADInfo s_WPADInfoOld[4];

[[address(0x80378068)]]
WPADInfo s_WPADInfoTmpOld[4];

void initWPADInfo();

[[address(0x8016F330)]]
void create()
{
    g_padMg = EGG::CoreControllerMgr::sInstance;
    initWPADInfo();
    beginPad();
    endPad();
}

[[address(0x8016F360)]]
void beginPad()
{
    g_PadFrame++;

    g_padMg->beginFrame();

    for (int i = 0; i < PAD_CHAN_COUNT; i++) {
        EGG::CoreController* core = g_padMg->getNthController(i);
        g_core[i] = core;

        if (core->mFlag.off(1)) {
            if (!g_IsConnected[i]) {
                continue;
            }

            core->maStatus[0].init();
            core->sceneReset();

            g_PadAdditionalData[i][0] = 0.0f;
            g_PadAdditionalData[i][1] = 0.0f;
            g_PadAdditionalData[i][2] = 0.0f;
            g_PadAdditionalData[i][3] = 0.0f;
            g_PadAdditionalData[i][4] = 0.0f;
            g_PadAdditionalData[i][5] = 0.0f;

            clearWPADInfo(static_cast<CH_e>(i));

            g_IsConnected[i] = false;
        } else {
            f32 xDiff = core->maStatus[0].acc_vertical.x - g_PadAdditionalData[i][0];
            f32 yDiff = core->maStatus[0].acc_vertical.y - g_PadAdditionalData[i][1];
            f32 xDiff2 = xDiff - g_PadAdditionalData[i][2];
            f32 yDiff2 = yDiff - g_PadAdditionalData[i][3];

            g_PadAdditionalData[i][0] = core->maStatus[0].acc_vertical.x;
            g_PadAdditionalData[i][1] = core->maStatus[0].acc_vertical.y;
            g_PadAdditionalData[i][2] = xDiff;
            g_PadAdditionalData[i][3] = yDiff;
            g_PadAdditionalData[i][4] = xDiff2;
            g_PadAdditionalData[i][5] = yDiff2;

            g_IsConnected[i] = true;

            if (s_GetWPADInfoInterval != 0 &&
                (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == i ||
                 (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
                if (i < 4) {
                    getWPADInfoAsync(static_cast<CH_e>(i));
                } else {
                    // Fake WPAD info
                    s_WPADInfo[i] = {
                      .dpd = false,
                      .speaker = false,
                      .attach = false,
                      .lowBat = false,
                      .nearempty = false,
                      .battery = 0,
                      .led = 0,
                      .protocol = 0,
                      .firmware = 0
                    };
                    s_WPADInfoAvailable[i] = true;
                }
            }
        }
    }

    if (s_GetWPADInfoInterval <= s_GetWPADInfoCount++) {
        s_GetWPADInfoCount = 0;
    }

    g_currentCore = g_core[static_cast<int>(g_currentCoreID)];
}

[[address(0x8016F550)]]
void endPad();

[[address(0x8016F570)]]
void setCurrentChannel(CH_e chan);

[[address(0x8016F5A0)]]
int getBatteryLevel_ch(CH_e chan)
{
    if (chan <= CH_e::CHAN_3 && s_WPADInfoAvailable[static_cast<int>(chan)]) {
        return s_WPADInfo[static_cast<int>(chan)].battery;
    }
    return 4;
}

[[address(0x8016F640)]]
void clearWPADInfo(CH_e chan)
{
    s_WPADInfo[static_cast<int>(chan)] = {};
    s_WPADInfoAvailable[static_cast<int>(chan)] = false;
}

[[address(0x8016F690)]]
void initWPADInfo()
{
    for (int i = 0; i < 4; i++) {
        s_WPADInfoAvailable[i] = s_WPADInfoAvailableOld[i];
        g_PadAdditionalData[i][0] = g_PadAdditionalDataOld[i][0];
        g_PadAdditionalData[i][1] = g_PadAdditionalDataOld[i][1];
        g_PadAdditionalData[i][2] = g_PadAdditionalDataOld[i][2];
        g_PadAdditionalData[i][3] = g_PadAdditionalDataOld[i][3];
        g_PadAdditionalData[i][4] = g_PadAdditionalDataOld[i][4];
        g_PadAdditionalData[i][5] = g_PadAdditionalDataOld[i][5];
        s_WPADInfo[i] = s_WPADInfoOld[i];
        s_WPADInfoTmp[i] = s_WPADInfoTmpOld[i];
    }

    for (int i = 4; i < PAD_CHAN_COUNT; i++) {
        clearWPADInfo(static_cast<CH_e>(i));
    }
}

[[address(0x8016F710)]]
int getWPADInfoAsync(CH_e chan);

bool isGameCubeChannel(CH_e chan)
{
    return EGG::CoreControllerMgr::isGameCubeChannel(static_cast<WPADChannel>(chan));
}

PATCH_REFERENCES(
  g_core,
  {
    {0x80017EEA, R_PPC_ADDR16_HA}, {0x80017EF6, R_PPC_ADDR16_LO}, {0x800582CA, R_PPC_ADDR16_HA},
    {0x800582CE, R_PPC_ADDR16_LO}, {0x800B540E, R_PPC_ADDR16_HA}, {0x800B5416, R_PPC_ADDR16_LO},
    {0x800B542E, R_PPC_ADDR16_HA}, {0x800B5436, R_PPC_ADDR16_LO}, {0x800B5E0E, R_PPC_ADDR16_HA},
    {0x800B5E1A, R_PPC_ADDR16_LO}, {0x800B5EBE, R_PPC_ADDR16_HA}, {0x800B5EC2, R_PPC_ADDR16_LO},
    {0x800B6456, R_PPC_ADDR16_HA}, {0x800B645A, R_PPC_ADDR16_LO}, {0x800D074E, R_PPC_ADDR16_HA},
    {0x800D0766, R_PPC_ADDR16_LO}, {0x800D088A, R_PPC_ADDR16_HA}, {0x800D088E, R_PPC_ADDR16_LO},
    {0x800D0892, R_PPC_ADDR16_LO}, {0x800D0DFE, R_PPC_ADDR16_HA}, {0x800D0E06, R_PPC_ADDR16_LO},
    {0x800D116A, R_PPC_ADDR16_HA}, {0x800D1172, R_PPC_ADDR16_LO}, {0x800D89BE, R_PPC_ADDR16_HA},
    {0x800D89C2, R_PPC_ADDR16_LO}, {0x800D8A82, R_PPC_ADDR16_HA}, {0x800D8A92, R_PPC_ADDR16_LO},
    {0x800D8B86, R_PPC_ADDR16_HA}, {0x800D8B8A, R_PPC_ADDR16_LO}, {0x800D8D0E, R_PPC_ADDR16_HA},
    {0x800D8D12, R_PPC_ADDR16_LO}, {0x800D8E4E, R_PPC_ADDR16_HA}, {0x800D8E56, R_PPC_ADDR16_LO},
    {0x800D8EE6, R_PPC_ADDR16_HA}, {0x800D8EEA, R_PPC_ADDR16_LO}, {0x800D988A, R_PPC_ADDR16_HA},
    {0x800D9892, R_PPC_ADDR16_LO}, {0x800DC7EA, R_PPC_ADDR16_HA}, {0x800DC7F2, R_PPC_ADDR16_LO},
    {0x800DC86E, R_PPC_ADDR16_HA}, {0x800DC872, R_PPC_ADDR16_LO}, {0x800DC956, R_PPC_ADDR16_HA},
    {0x800DC95A, R_PPC_ADDR16_LO}, {0x800DC9DA, R_PPC_ADDR16_HA}, {0x800DC9E2, R_PPC_ADDR16_LO},
    {0x800DCAB6, R_PPC_ADDR16_HA}, {0x800DCABA, R_PPC_ADDR16_LO}, {0x800DCB2A, R_PPC_ADDR16_HA},
    {0x800DCB3A, R_PPC_ADDR16_LO}, {0x800DCC6A, R_PPC_ADDR16_HA}, {0x800DCC72, R_PPC_ADDR16_LO},
    {0x800DCD9A, R_PPC_ADDR16_HA}, {0x800DCDA2, R_PPC_ADDR16_LO}, {0x800DCECA, R_PPC_ADDR16_HA},
    {0x800DCED2, R_PPC_ADDR16_LO}, {0x80101106, R_PPC_ADDR16_HA}, {0x8010110E, R_PPC_ADDR16_LO},
    {0x80109C4A, R_PPC_ADDR16_HA}, {0x80109C5E, R_PPC_ADDR16_LO}, {0x80109D26, R_PPC_ADDR16_HA},
    {0x80109D2E, R_PPC_ADDR16_LO}, {0x8010A15A, R_PPC_ADDR16_HA}, {0x8010A15E, R_PPC_ADDR16_LO},
    {0x8010D9E6, R_PPC_ADDR16_HA}, {0x8010D9F6, R_PPC_ADDR16_LO}, {0x8010DA96, R_PPC_ADDR16_HA},
    {0x8010DAA6, R_PPC_ADDR16_LO}, {0x8010DB46, R_PPC_ADDR16_HA}, {0x8010DB56, R_PPC_ADDR16_LO},
    {0x8016F39E, R_PPC_ADDR16_HA}, {0x8016F3AA, R_PPC_ADDR16_LO}, {0x8016F512, R_PPC_ADDR16_HA},
    {0x8016F516, R_PPC_ADDR16_LO}, {0x8016F576, R_PPC_ADDR16_HA}, {0x8016F582, R_PPC_ADDR16_LO},
    {0x807705A6, R_PPC_ADDR16_HA}, {0x807705AA, R_PPC_ADDR16_LO}, {0x8077094A, R_PPC_ADDR16_HA},
    {0x8077095A, R_PPC_ADDR16_LO}, {0x80811F6E, R_PPC_ADDR16_HA}, {0x80811F72, R_PPC_ADDR16_LO},
    {0x80916B52, R_PPC_ADDR16_HA}, {0x80916B5A, R_PPC_ADDR16_LO}, {0x8092592E, R_PPC_ADDR16_HA},
    {0x80925936, R_PPC_ADDR16_LO}, {0x80A97CEA, R_PPC_ADDR16_HA}, {0x80A97CF6, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  g_PadAdditionalData,
  {
    {0x800B5E12, R_PPC_ADDR16_HA},
    {0x800B5E26, R_PPC_ADDR16_LO},
    {0x8016F3A2, R_PPC_ADDR16_HA},
    {0x8016F3AE, R_PPC_ADDR16_LO},
    {0x8016F7BA, R_PPC_ADDR16_HA},
    {0x8016F7CE, R_PPC_ADDR16_LO},
    {0x8016F862, R_PPC_ADDR16_HA},
    {0x8016F86A, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  s_WPADInfo,
  {
    {0x8016F5B6, R_PPC_ADDR16_HA},
    {0x8016F5BA, R_PPC_ADDR16_LO},
    {0x8016F5D6, R_PPC_ADDR16_HA},
    {0x8016F5E2, R_PPC_ADDR16_LO},
    {0x8016F646, R_PPC_ADDR16_HA},
    {0x8016F64E, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  s_WPADInfo,
  {
    {0x8016F6F6, R_PPC_ADDR16_HA},
    {0x8016F6FA, R_PPC_ADDR16_LO},
    {0x8016F71A, R_PPC_ADDR16_HA},
    {0x8016F72A, R_PPC_ADDR16_LO},
  }
);

} // namespace mPad
