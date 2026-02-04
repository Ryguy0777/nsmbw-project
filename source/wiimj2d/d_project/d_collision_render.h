#pragma once

#include "machine/m_3d.h"

class dCollisionRender_c : public m3d::proc_c
{
public:
    // Structors
    // ^^^^^^

    dCollisionRender_c();

public:
    // Virtual Functions
    // ^^^^^^

    virtual void drawOpa();
    virtual void drawXlu();

public:
    // Static Variables
    // ^^^^^^

    static dCollisionRender_c m_instance;
};