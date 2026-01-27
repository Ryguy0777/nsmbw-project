// d_nextgoto_sort.cpp
// nsmbw-project

#include "d_nextgoto_sort.h"
#include <cstring>

dNextGotoSort_c::dNextGotoSort_c(u16* lookupTable, cRnd_c& rnd)
{
    m_entryLookup = lookupTable;
    m_rnd = rnd;

    m_excEntIndex = 0;
    m_excEntCount = 0;
    m_curGroupEnd = 0;

    m_entCount = 0;
    m_ptrEntList = m_entList;

    // Add grouped entries to the list first
    bool inGroup = false;
    for (u32 i = 0; i < m_inputCount; i++) {
        u32 entry = i | ((m_input[i] & 0xF000) << 16);
        u8 flags = (entry >> 28);
        if (!inGroup && flags == 0x0) {
            continue;
        }

        // Write index and group flags
        m_entList[m_entCount++] = entry;

        if (flags & 0x2) {
            inGroup = false;
        } else if (flags & 0x1) {
            inGroup = true;
        } else if (flags & 0x3) {
            // If the entrance is by itself in a group then move it to
            // exclusive
            MoveToExclusive(m_entCount - 1);
        }

        m_entryLookup[i] = 0;
    }

    // Add non-grouped entries to the list
    inGroup = false;
    u32 lastGroupedEnt = m_entCount;
    for (u32 i = 0; i < m_inputCount; i++) {
        // Write index and copy group flags
        u32 entry = i | ((m_input[i] & 0xF000) << 16);
        u8 flags = (entry >> 28);
        if (inGroup || flags != 0x0) {
            if (flags & 0x2) {
                inGroup = false;
            } else if (flags & 0x1) {
                inGroup = true;
            }

            continue;
        }

        // Write index
        m_entList[m_entCount++] = entry;
    }

    // Reserve a random non-exclusive entrance for the last link
    u32 idx = lastGroupedEnt + m_rnd.next(m_entCount - lastGroupedEnt);
    m_lastEntrance = m_entList[idx];
    Remove(idx);
}

void dNextGotoSort_c::CreateLookupTable()
{
    while (m_entCount > 0) {
        u32 ent1 = SelectEntrance1();
        u32 ent2 = SelectEntrance2() & 0x0FFFFFFF;

        ent1 &= 0x0FFFFFFF;

        m_entryLookup[ent1] = ent2;
        m_entryLookup[ent2] = ent1;
    }
}

u32 dNextGotoSort_c::SelectEntrance1()
{
    // Exclusive entrances always go first
    if (m_excEntCount != 0) {
        m_excEntCount--;
        return m_excEntList[m_excEntIndex++];
    }

    // Reset exclusive index
    m_excEntIndex = 0;

    if (m_curGroupEnd == 0) {
        // Not in a group
        u32 val = m_ptrEntList[0];
        if ((val >> 28) != 0x1) {
            RemoveEntrance(0);
            return val;
        }

        // Start of a group, let's find the end
        for (u32 i = 0; i < m_entCount; i++) {
            if ((m_ptrEntList[i] >> 28) == 0x2) {
                m_curGroupEnd = i + 1;
                break;
            }
        }

        // Then fall through to the group code
    }

    // Randomly select an entrance within the group. This will make sure
    // that which entry ends up exclusive will be evenly distributed.
    u32 i = m_rnd.next(m_curGroupEnd);
    u32 val = m_ptrEntList[i];
    RemoveEntrance(i);

    return val;
}

u32 dNextGotoSort_c::SelectEntrance2()
{
    // Entrance 2 cannot be an exclusive entrance
    u32 i = m_rnd.next(m_entCount);
    u32 val = m_ptrEntList[i];
    RemoveEntrance(i);

    return val;
}

void dNextGotoSort_c::MoveToExclusive(u32 idx)
{
    u32 val = m_ptrEntList[idx];
    Remove(idx);
    m_excEntList[m_excEntIndex + m_excEntCount] = val;
    m_excEntCount++;
}

void dNextGotoSort_c::Remove(u32 idx)
{
    if (idx < m_curGroupEnd) {
        m_curGroupEnd--;
    }

    if (idx == 0) {
        m_ptrEntList += 1;
        m_entCount -= 1;
        return;
    }

    if (idx == (m_entCount - 1)) {
        m_entCount -= 1;
        return;
    }

    std::memmove(m_ptrEntList + idx, m_ptrEntList + idx + 1, (m_entCount - idx - 1) * sizeof(u32));
    m_entCount -= 1;
}

void dNextGotoSort_c::RemoveEntrance(u32 idx)
{
    u32 val = m_ptrEntList[idx];

    if ((val >> 28) == 0x1) {
        // Start of group
        m_ptrEntList[idx + 1] |= 0x1 << 28;
        if ((m_ptrEntList[idx + 1] >> 28) == 0x3) {
            MoveToExclusive(idx + 1);
        }
    }

    if ((val >> 28) == 0x2) {
        // End of group
        m_ptrEntList[idx - 1] |= 0x2 << 28;
        if ((m_ptrEntList[idx - 1] >> 28) == 0x3) {
            MoveToExclusive(idx - 1);
            idx--;
        }
    }

    Remove(idx);
}
