// d_nextgoto_list.cpp
// nsmbw-project

#include "d_nextgoto_list.h"

#include "component/c_json.h"
#include "d_system/d_dvd.h"
#include "machine/m_heap.h"
#include <cstdlib>
#include <cstring>

constinit dNextGotoList_c dNextGotoList_c::ms_instance;

dNextGotoList_c& dNextGotoList_c::create()
{
    if (!ms_instance.empty()) {
        return ms_instance;
    }

    std::size_t dataSize = 0;
    char* data = readResource(dataSize);
    if (data == nullptr) {
        return ms_instance;
    }

    std::destroy_at(&ms_instance);
    std::construct_at<dNextGotoList_c>(&ms_instance, data, dataSize);

    freeResource(data);
    return ms_instance;
}

char* dNextGotoList_c::readResource(std::size_t& outSize)
{
    dDvd::loader_c loader;
    void* data = loader.request("/Info/PipeRandomizer.jsonc", 0, mHeap::g_gameHeaps[2]);
    if (data == nullptr) {
        outSize = 0;
        return nullptr;
    }
    outSize = loader.getSize();
    return static_cast<char*>(data);
}

void dNextGotoList_c::freeResource(char* data)
{
    mHeap::g_gameHeaps[2]->free(data);
}

dNextGotoList_c::dNextGotoList_c(const char* data, std::size_t dataSize)
{
    bool read = false;
    if (!cJsonParser_c::parse(
          this, const_cast<char*>(data), dataSize,
          [](void* buffer, std::size_t size, void* userData) -> int {
        bool& read = *static_cast<bool*>(userData);
        if (read) {
            return 0;
        }
        read = true;
        return static_cast<int>(size);
    }, &read
        )) {
        clear();
        return;
    }

    if (size() % 2) {
        // Ensure an even number of entries for pairing. Use the unused Coin Battle-2 area
        push_back({
          .world = 2 - 1,
          .stage = 20 - 1,
          .course = 2 - 1,
          .nextgoto = 1,
          .group_start = true,
          .group_end = true,
        });
    }
}

void dNextGotoList_c::randomize(s32 seed)
{
    m_seed = seed;
    m_lookupTable.clear();
    m_lookupTable.resize(size(), Index());
    Randomizer_c rndizer(
      data(), static_cast<Index>(size()), m_lookupTable.data(), cRnd_c(static_cast<u32>(m_seed))
    );
    rndizer.createLookupTable();
}

bool dNextGotoList_c::value(s64 number)
{
    if (m_state != State_e::COURSE && m_state != State_e::GROUP) {
        return false;
    }

    m_entry.nextgoto = static_cast<u32>(number);
    push_back(m_entry);
    m_entry.group_start = false;
    m_groupHasEntry = true;
    return true;
}

bool dNextGotoList_c::key(const char* str, std::size_t length, bool copy)
{
    if (m_nextState != m_state) {
        return false;
    }

    switch (m_state) {
    default:
        return false;
    case State_e::ROOT: {
        // Stage Name "%02d-%02d"
        int world = std::atoi(str);
        if (world < 0) {
            return false;
        }
        const char* dash = std::strchr(str, '-');
        if (dash == nullptr) {
            return false;
        }
        int stage = std::atoi(dash + 1);
        if (stage < 0) {
            return false;
        }
        m_entry.world = static_cast<u32>(world);
        m_entry.stage = static_cast<u32>(stage);
        m_nextState = State_e::STAGE;
        return true;
    }

    case State_e::STAGE: {
        // Course/Area Name "c%d"
        if (length < 2 || str[0] != 'c' || str[1] < '1' || str[1] > '4') {
            return false;
        }
        int course = str[1] - '1';
        m_entry.course = static_cast<u32>(course);
        m_nextState = State_e::COURSE;
        return true;
    }
    }
}

bool dNextGotoList_c::string(const char* str, std::size_t length, bool copy)
{
    int number = std::atoi(str);
    return value(static_cast<s64>(number));
}

bool dNextGotoList_c::startObject()
{
    if (m_state == State_e::NONE) {
        m_state = m_nextState = State_e::ROOT;
        return true;
    }
    if (m_nextState <= m_state) {
        return false;
    }

    m_state = m_nextState;
    return true;
}

bool dNextGotoList_c::endObject()
{
    if (m_state == State_e::NONE) {
        return false;
    }
    if (m_state == State_e::ROOT) {
        m_state = m_nextState = State_e::NONE;
        return true;
    }
    if (m_state == State_e::STAGE) {
        m_state = m_nextState = State_e::ROOT;
        return true;
    }
    return false;
}

bool dNextGotoList_c::startArray()
{
    if (m_state == State_e::COURSE) {
        m_state = m_nextState = State_e::GROUP;
        m_entry.group_start = true;
        m_groupHasEntry = false;
        return true;
    }
    if (m_state != State_e::STAGE || m_nextState != State_e::COURSE) {
        return false;
    }
    m_state = m_nextState = State_e::COURSE;
    return true;
}

bool dNextGotoList_c::endArray()
{
    if (m_state == State_e::GROUP) {
        if (m_groupHasEntry) {
            back().group_end = true;
        }
        m_entry.group_start = false;
        m_state = m_nextState = State_e::COURSE;
        return true;
    }
    if (m_state == State_e::COURSE) {
        m_state = m_nextState = State_e::STAGE;
        return true;
    }
    return false;
}

#pragma clang diagnostic ignored "-Wc++11-narrowing"

dNextGotoList_c::Randomizer_c::Randomizer_c(
  Entry_s* input, Index inputCount, Index* lookupTable, cRnd_c&& rnd
)
  : m_inputCount(inputCount)
  , m_pInput(input)
  , m_entList(new LookupEntry_s[inputCount])
  , m_entCount(0)
  , m_pEntList(m_entList)
  , m_excEntList(new LookupEntry_s[inputCount])
  , m_excEntCount(0)
  , m_excEntIndex(0)
  , m_curGroupEnd(0)
  , m_lastEntrance(0)
  , m_pEntryLookup(lookupTable)
  , m_rnd(rnd)
{
    // Add grouped entries to the list first
    bool inGroup = false;
    for (u16 i = 0; i < m_inputCount; i++) {
        LookupEntry_s entry = {i, m_pInput[i].group_start, m_pInput[i].group_end};
        if (!inGroup && entry.group_start == 0 && entry.group_end == 0) {
            continue;
        }

        // Write index and group flags
        m_entList[m_entCount++] = entry;

        if (entry.group_start && entry.group_end) {
            // If the entrance is by itself in a group then move it to
            // exclusive
            setExclusive(m_entCount - 1);
        } else if (entry.group_end) {
            inGroup = false;
        } else if (entry.group_start) {
            inGroup = true;
        }

        m_pEntryLookup[i] = 0;
    }

    // Add non-grouped entries to the list
    inGroup = false;
    u32 lastGroupedEnt = m_entCount;
    for (u16 i = 0; i < m_inputCount; i++) {
        // Write index and copy group flags
        LookupEntry_s entry = {i, m_pInput[i].group_start, m_pInput[i].group_end};
        if (entry.group_end) {
            inGroup = false;
            continue;
        } else if (entry.group_start) {
            inGroup = true;
            continue;
        } else if (inGroup) {
            continue;
        }

        // Write index
        m_entList[m_entCount++] = entry;
    }

    // Reserve a random non-exclusive entrance for the last link
    u32 index = lastGroupedEnt + m_rnd.next(m_entCount - lastGroupedEnt);
    m_lastEntrance = m_entList[index].index;
    remove(index);
}

void dNextGotoList_c::Randomizer_c::createLookupTable()
{
    while (m_entCount > 0) {
        LookupEntry_s ent1 = select1();
        LookupEntry_s ent2 = select2();

        m_pEntryLookup[ent1.index] = ent2.index;
        m_pEntryLookup[ent2.index] = ent1.index;
    }
}

dNextGotoList_c::LookupEntry_s dNextGotoList_c::Randomizer_c::select1()
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
        LookupEntry_s entry = m_pEntList[0];
        if (!entry.group_start) {
            removeUpdate(0);
            return entry;
        }

        // Start of a group, let's find the end
        for (u32 i = 1; i < m_entCount; i++) {
            if (m_pEntList[i].group_end) {
                m_curGroupEnd = i + 1;
                break;
            }
        }

        // Then fall through to the group code
    }

    // Randomly select an entrance within the group. This will make sure
    // that which entry ends up exclusive will be evenly distributed.
    u32 i = m_rnd.next(m_curGroupEnd);
    LookupEntry_s entry = m_pEntList[i];
    removeUpdate(i);

    return entry;
}

dNextGotoList_c::LookupEntry_s dNextGotoList_c::Randomizer_c::select2()
{
    // Entrance 2 cannot be an exclusive entrance
    u32 i = m_rnd.next(m_entCount);
    LookupEntry_s entry = m_pEntList[i];
    removeUpdate(i);

    return entry;
}

void dNextGotoList_c::Randomizer_c::setExclusive(Index index)
{
    LookupEntry_s val = m_pEntList[index];
    remove(index);
    m_excEntList[m_excEntIndex + m_excEntCount] = val;
    m_excEntCount++;
}

void dNextGotoList_c::Randomizer_c::remove(Index index)
{
    if (index < m_curGroupEnd) {
        m_curGroupEnd--;
    }

    if (index == 0) {
        m_pEntList += 1;
        m_entCount -= 1;
        return;
    }

    if (index == (m_entCount - 1)) {
        m_entCount -= 1;
        return;
    }

    std::memmove(
      m_pEntList + index, m_pEntList + index + 1, (m_entCount - index - 1) * sizeof(LookupEntry_s)
    );
    m_entCount -= 1;
}

void dNextGotoList_c::Randomizer_c::removeUpdate(Index index)
{
    LookupEntry_s entry = m_pEntList[index];

    if (entry.group_start) {
        m_pEntList[index + 1].group_start = true;
        if (m_pEntList[index + 1].group_start && m_pEntList[index + 1].group_end) {
            setExclusive(index + 1);
        }
    }

    if (entry.group_end) {
        m_pEntList[index - 1].group_end = true;
        if (m_pEntList[index - 1].group_start && m_pEntList[index - 1].group_end) {
            setExclusive(index - 1);
            index--;
        }
    }

    remove(index);
}
