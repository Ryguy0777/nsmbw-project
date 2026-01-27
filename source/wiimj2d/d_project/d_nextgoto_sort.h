#pragma once

#include "component/c_random.h"

class dNextGotoSort_c
{
public:
    // Structors
    // ^^^^^^

    dNextGotoSort_c(u16* lookupTable, cRnd_c& rnd);

public:
    // Instance Methods
    // ^^^^^^

    void CreateLookupTable();
    u32 SelectEntrance1();
    u32 SelectEntrance2();
    void MoveToExclusive(u32 idx);
    void Remove(u32 idx);
    void RemoveEntrance(u32 idx);

public:
    // Instance Variables
    // ^^^^^^

    u32 m_inputCount;
    u32* m_input;

    u32* m_entList;
    u32 m_entCount;
    u32* m_ptrEntList;

    u32* m_excEntList;
    u32 m_excEntCount;
    u32 m_excEntIndex;

    u32 m_curGroupEnd;

    u32 m_lastEntrance;

    u16* m_entryLookup;

    cRnd_c m_rnd;
};