#
# WIIMJ2D.dol
# NSMBW          TODO
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80269130 - 0x802697A0
    DvdSoundArchive.cpp

# NSMBW: 0x80275530 - 0x80275780
    SoundActor.cpp
# NSMBW          .text:  0x80275780 - 0x80275E80
    SoundArchive.cpp
# NSMBW          .text:  0x80275E80 - 0x80277190
    SoundArchiveFile.cpp
# NSMBW          .text:  0x80277190 - 0x802777F0
    SoundArchiveLoader.cpp

# NSMBW          .text:  0x802836F0 - 0x80283BD0
    Util.cpp
)