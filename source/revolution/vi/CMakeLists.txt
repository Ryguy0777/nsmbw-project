#
# WIIMJ2D.dol
# NSMBW          TODO
#
target_sources(project PRIVATE
# NSMBW          .text:  0x801BBB70 - 0x801BE5C0
    vi.c
# NSMBW          .text:  0x801BE5C0 - 0x801BEEE0
    i2c.c
# NSMBW          .text:  0x801BEEE0 - 0x801C0610
    vi3in1.c
)