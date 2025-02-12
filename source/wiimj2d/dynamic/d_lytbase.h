#pragma once

#include <dynamic/d_2d.h>
#include <dynamic/d_lyttextbox.h>
#include <nw4r/lyt/Layout.h>
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include <nw4r/lyt/TextBox.h>
#include <nw4r/lyt/Window.h>

class LytBase_c : public d2d::Multi_c
{
    SIZE_ASSERT(0x198);

public:
    /* 0x800C89A0 */
    LytBase_c();

    /* VT+0x08 0x800C89F0 */
    virtual ~LytBase_c() override;

    /* VT+0x14 0x800C8A60 */
    virtual bool build(const char* lytName, d2d::ResAccMult_c* resAcc) override;

    /* 0x800C8D00 */
    bool ReadResource(const char* arcName, bool param2);

    /* 0x800C8E50 */
    void NPaneRegister(const char** paneNames, nw4r::lyt::Pane** nullPanes, int count);

    /* 0x800C8EC0 */
    void WPaneRegister(const char** paneNames, nw4r::lyt::Window** windowPanes, int count);

    /* 0x800C8F30 */
    void PPaneRegister(const char** paneNames, nw4r::lyt::Picture** picturePanes, int count);

    /* 0x800C8FA0 */
    void TPaneRegister(const char** paneNames, LytTextBox_c** textBoxPanes, int count);

    /* 0x800C9010 */
    void TPaneNameRegister(const char** paneNames, const int* param2, int param3, int count);

    /* 0x800C90A0 */
    void AnimeResRegister(const char** animNames, int count);

    /* 0x800C91E0 */
    void GroupRegister(const char** groupNames, const int* param2, int count);

    /* 0x800C93E0 */
    void AnimeStartSetup(int group, bool param2);

    /* 0x800C94C0 */
    void ReverseAnimeStartSetup(int group, bool param2);

    /* 0x800C9580 */
    void AnimeEndSetup(int param1);

    /* 0x800C95F0 */
    void AllAnimeEndSetup();

    /* 0x800C9700 */
    bool isAnime(int group);

    FILL(0x0AC, 0x198);
};