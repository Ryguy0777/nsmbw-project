// Port.h - Compile-time address porter

#pragma once

#include <cstddef>
#include <cstdint>

namespace Port
{

enum class Region {
    Error,
    P1,
    P2,
    E1,
    E2,
    J1,
    J2,
    K,
    W,
    C,
};

constexpr char AddressMapFile[] = {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc23-extensions"
#embed "../address-map.txt"
#pragma clang diagnostic pop
};

class AddressMapper;

static constexpr const AddressMapper& GetAddressMapper(Region region);

class AddressMapper
{
private:
    struct AddressRange {
        std::uint32_t low;
        std::uint32_t high;
        std::int32_t offset;
    };

    Region m_region = Region::Error;
    Region m_extend = Region::Error;
    AddressRange m_ranges[1024] = {};
    std::size_t m_rangeCount = 0;

public:
    constexpr AddressMapper(Region region)
    {
        // Cycle through the address map file to find the region
        std::size_t index = 0;
        for (; index < sizeof(AddressMapFile); index = NextLine(index)) {
            Region regionMarker = ConsumeRegionMarker(index);
            if (regionMarker == region) {
                m_region = region;
                break;
            }
        }

        // If the region was not found, return
        if (m_region == Region::Error) {
            return;
        }

        std::size_t firstLine = 0;
        // Cycle through the address map file to find the extend region and first line
        for (index = NextLine(index); index < sizeof(AddressMapFile); index = NextLine(index)) {
            Region extend = ConsumeExtend(index);
            if (extend != Region::Error) {
                m_extend = extend;
                continue;
            }

            std::size_t currentLine = index;
            index = SkipWhitespace(index);
            if (IsHexDigit(AddressMapFile[index])) {
                firstLine = currentLine;
                break;
            }
        }

        Assert(firstLine != 0);

        // Cycle through the address map file to find the address ranges
        for (index = firstLine; index < sizeof(AddressMapFile); index = NextLine(index)) {
            index = SkipWhitespace(index);

            // If we reach a region marker then that's the end of our section
            if (AddressMapFile[index] == '[') {
                break;
            }

            // Check if we have a digit
            if (!IsHexDigit(AddressMapFile[index])) {
                continue;
            }

            // Parse the low range address
            AddressRange& range = m_ranges[m_rangeCount++];
            range.low = ParseUint(index);

            Assert(AddressMapFile[index++] == '-');

            // Parse the high range address
            if (AddressMapFile[index] == '*') {
                range.high = 0xFFFFFFFF;
                index++;
            } else {
                range.high = ParseUint(index);
            }

            index = SkipWhitespace(index);
            Assert(AddressMapFile[index++] == ':');
            index = SkipWhitespace(index);

            // Parse the offset
            bool negative = false;
            if (AddressMapFile[index] == '-') {
                negative = true;
            } else if (AddressMapFile[index] != '+') {
                continue;
            }

            index++;
            Assert(AddressMapFile[index++] == '0');
            Assert(AddressMapFile[index++] == 'x');
            range.offset = ParseUint(index);
            if (negative) {
                range.offset = -range.offset;
            }
        }
    }

private:
    static void AssertFail();

    static constexpr void Assert(bool condition)
    {
        if (!condition) {
            AssertFail();
        }
    }

    static constexpr bool IsHexDigit(char c)
    {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
    }

    static constexpr std::uint32_t ParseUint(std::size_t& index)
    {
        std::uint32_t value = 0;
        for (; IsHexDigit(AddressMapFile[index]); index++) {
            value <<= 4;
            if (AddressMapFile[index] >= 'a') {
                value |= AddressMapFile[index] - 'a' + 10;
            } else if (AddressMapFile[index] >= 'A') {
                value |= AddressMapFile[index] - 'A' + 10;
            } else {
                value |= AddressMapFile[index] - '0';
            }
        }

        return value;
    }

    static constexpr std::size_t NextLine(std::size_t index)
    {
        for (std::size_t i = index; i < sizeof(AddressMapFile); i++) {
            if (AddressMapFile[i] == '\n') {
                return i + 1;
            }
        }

        return sizeof(AddressMapFile);
    }

    static constexpr std::size_t SkipWhitespace(std::size_t index)
    {
        for (std::size_t i = index; i < sizeof(AddressMapFile); i++) {
            if (AddressMapFile[i] != ' ' && AddressMapFile[i] != '\t') {
                return i;
            }
        }

        return sizeof(AddressMapFile);
    }

    static constexpr Region ConsumeRegion(std::size_t index)
    {
        switch (AddressMapFile[index]) {
        case 'P':
            return AddressMapFile[index + 1] == '1' ? Region::P1 : Region::P2;
        case 'E':
            return AddressMapFile[index + 1] == '1' ? Region::E1 : Region::E2;
        case 'J':
            return AddressMapFile[index + 1] == '1' ? Region::J1 : Region::J2;
        case 'K':
            return Region::K;
        case 'W':
            return Region::W;
        case 'C':
            return Region::C;
        default:
            return Region::Error;
        }
    }

    static constexpr Region ConsumeRegionMarker(std::size_t index)
    {
        index = SkipWhitespace(index);
        if (AddressMapFile[index] != '[') {
            return Region::Error;
        }

        return ConsumeRegion(index + 1);
    }

    static constexpr Region ConsumeExtend(std::size_t index)
    {
        index = SkipWhitespace(index);
        for (int i = 0; i < sizeof("extend ") - 1; i++) {
            if (AddressMapFile[index++] != "extend "[i]) {
                return Region::Error;
            }
        }

        return ConsumeRegion(SkipWhitespace(index));
    }

public:
    constexpr std::uint32_t MapAddress(std::uint32_t srcAddr) const
    {
        if (m_extend != Region::Error && m_extend != Region::P1) {
            srcAddr = GetAddressMapper(m_extend).MapAddress(srcAddr);
        }

        // Binary search for the address range
        std::size_t low = 0;
        std::size_t high = m_rangeCount;
        while (low < high) {
            std::size_t mid = (low + high) / 2;
            const AddressRange& range = m_ranges[mid];
            if (srcAddr >= range.low && srcAddr <= range.high) {
                return srcAddr + range.offset;
            }

            if (srcAddr < range.low) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return 0;
    }
};

constexpr AddressMapper AddressMapperP2(Region::P2);
constexpr AddressMapper AddressMapperE1(Region::E1);
constexpr AddressMapper AddressMapperE2(Region::E2);
constexpr AddressMapper AddressMapperJ1(Region::J1);
constexpr AddressMapper AddressMapperJ2(Region::J2);
constexpr AddressMapper AddressMapperK(Region::K);
constexpr AddressMapper AddressMapperW(Region::W);
constexpr AddressMapper AddressMapperC(Region::C);

static constexpr const AddressMapper& GetAddressMapper(Region region)
{
    switch (region) {
    case Region::P2:
        return AddressMapperP2;
    case Region::E1:
        return AddressMapperE1;
    case Region::E2:
        return AddressMapperE2;
    case Region::J1:
        return AddressMapperJ1;
    case Region::J2:
        return AddressMapperJ2;
    case Region::K:
        return AddressMapperK;
    case Region::W:
        return AddressMapperW;
    case Region::C:
        return AddressMapperC;
    default:
        return AddressMapperP2;
    }
}

// Some tests
static_assert(GetAddressMapper(Region::P2).MapAddress(0x8005EA6A) == 0x8005EA6A);
static_assert(GetAddressMapper(Region::E1).MapAddress(0x8010F234) == 0x8010F100);
static_assert(GetAddressMapper(Region::E1).MapAddress(0x800CF6F8) == 0x800CF608);
static_assert(GetAddressMapper(Region::E2).MapAddress(0x800CF6F8) == 0x800CF610);
static_assert(GetAddressMapper(Region::J1).MapAddress(0x80779C1C) == 0x80779AEC);
static_assert(GetAddressMapper(Region::W).MapAddress(0x800B34D0) == 0x800B3650);

} // namespace Port