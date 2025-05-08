// snd_SoundArchiveFile.cpp
// NSMBW .text: 0x80275E80 - 0x80277190

#include "SoundArchiveFile.h"

#include <revolution/os.h>

namespace nw4r::snd::detail
{

static constexpr u32 TOADETTE_BANK = 1000;
static constexpr u32 TOADETTE_BANK_FILE_ID = 1000;

// Hack, i wanna do this better and not embedded in nw4r later, but this is more of a PoC patch

static bool IsToadetteSound(u32 id)
{
    return id >= 5010 && id <= 5079;
}

static u32 GetBaseToadetteSoundId(u32 id)
{
    if (IsToadetteSound(id)) {
        return id - (5010 - 1010);
    }
    return id;
}

EXTERN_REPL(
  0x80276020, //
  SoundType SoundArchiveFileReader::GetSoundTypeInternal(u32 id) const
);

[[address(0x80276020)]]
SoundType SoundArchiveFileReader::GetSoundType(u32 id) const
{
    return GetSoundTypeInternal(GetBaseToadetteSoundId(id));
}

EXTERN_REPL(
  0x80276110, //
  bool SoundArchiveFileReader::ReadSoundInfoInternal(u32 id, SoundArchive::SoundInfo* pSoundInfo)
    const
);

[[address(0x80276110)]]
bool SoundArchiveFileReader::ReadSoundInfo(u32 id, SoundArchive::SoundInfo* pSoundInfo) const
{
    return ReadSoundInfoInternal(GetBaseToadetteSoundId(id), pSoundInfo);
}

EXTERN_REPL(
  0x80276350, //
  bool SoundArchiveFileReader::ReadSeqSoundInfoInternal(u32 id, SoundArchive::SeqSoundInfo* pInfo)
    const
);

[[address(0x80276350)]]
bool SoundArchiveFileReader::ReadSeqSoundInfo(u32 id, SoundArchive::SeqSoundInfo* pInfo) const
{
    bool result = ReadSeqSoundInfoInternal(GetBaseToadetteSoundId(id), pInfo);
    if (!result || !IsToadetteSound(id)) {
        return result;
    }

    pInfo->bankId = TOADETTE_BANK;
    return result;
}

[[address(0x80276630)]]
bool SoundArchiveFileReader::ReadBankInfo(u32 id, SoundArchive::BankInfo* pInfo) const
{
    if (id == TOADETTE_BANK) {
        pInfo->fileId = TOADETTE_BANK_FILE_ID;
        return true;
    }

    const SoundArchiveFile::BankInfo* pSrc = impl_GetBankInfo(id);

    if (pSrc == nullptr) {
        return false;
    }

    {
        const char* pLabel = GetString(pSrc->stringId);
        if (pLabel == nullptr) {
            pLabel = "Unknown";
        }

        OS_REPORT("SoundArchiveFileReader::ReadBankInfo: %s (%d)\n", pLabel, id);
    }

    pInfo->fileId = pSrc->fileId;

    return true;
}

[[address(0x802767A0)]]
bool SoundArchiveFileReader::ReadGroupInfo(u32 id, SoundArchive::GroupInfo* pInfo) const
{
    const SoundArchiveFile::GroupInfo* pSrc = impl_GetGroupInfo(id);

    if (pSrc == nullptr) {
        return false;
    }

    {
        const char* pLabel = GetString(pSrc->stringId);
        if (pLabel == nullptr) {
            pLabel = "Unknown";
        }

        OS_REPORT("SoundArchiveFileReader::ReadGroupInfo: %s (%d)\n", pLabel, id);
    }

    const SoundArchiveFile::GroupItemTable* pTable =
      Util::GetDataRefAddress0(pSrc->itemTableRef, mInfo);

    if (pTable == nullptr) {
        return false;
    }

    pInfo->extFilePath = Util::GetDataRefAddress0(pSrc->extFilePathRef, mInfo);
    pInfo->offset = pSrc->offset;
    pInfo->size = pSrc->size;
    pInfo->waveDataOffset = pSrc->waveDataOffset;
    pInfo->waveDataSize = pSrc->waveDataSize;
    pInfo->itemCount = pTable->count;

    return true;
}

[[address(0x80276B10)]]
const char* SoundArchiveFileReader::GetSoundLabelString(u32 id) const;

const char* SoundArchiveFileReader::GetString(u32 id) const
{
    if (id == 0xFFFFFFFF) {
        return nullptr;
    }

    if (mStringTable == nullptr) {
        return nullptr;
    }

    return static_cast<const char*>(GetPtrConst(mStringBase, mStringTable->offsetTable.items[id]));
}

const SoundArchiveFile::BankInfo* SoundArchiveFileReader::impl_GetBankInfo(u32 id) const
{
    const SoundArchiveFile::BankTable* pTable =
      Util::GetDataRefAddress0(mInfo->bankTableRef, mInfo);

    if (pTable == nullptr) {
        return nullptr;
    }

    if (id >= pTable->count) {
        return nullptr;
    }

    return Util::GetDataRefAddress0(pTable->items[id], mInfo);
}

const SoundArchiveFile::GroupInfo* SoundArchiveFileReader::impl_GetGroupInfo(u32 id) const
{
    const SoundArchiveFile::GroupTable* pTable =
      Util::GetDataRefAddress0(mInfo->groupTableRef, mInfo);

    if (pTable == nullptr) {
        return nullptr;
    }

    if (id >= pTable->count) {
        return nullptr;
    }

    return Util::GetDataRefAddress0(pTable->items[id], mInfo);
}

} // namespace nw4r::snd::detail