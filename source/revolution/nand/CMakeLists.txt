#
# WIIMJ2D.dol
# NSMBW           TODO
#
target_sources(project PRIVATE
# NSMBW           .text: 0x801D8620 - 0x801D95E0
    nand.c
# NSMBW           .text: 0x801D95E0 - 0x801DA250
    NANDOpenClose.c
# NSMBW           .text: 0x801DA250 - 0x801DB280
    NANDCore.c
# NSMBW           .text: 0x801DB1C0 - 0x801DB3F0
    NANDCheck.c
# NSMBW           .text: 0x801DB3F0 - 0x801DB980
    NANDLogging.c
# NSMBW           .text: 0x801DB980 - 0x801DB980
    NANDErrorMessage.c
)