
#
# WIIMJ2D.dol
# NSMBW          TODO
#
target_sources(project PRIVATE
# NSMBW          .init:  0x80004364 - 0x800046E4
# NSMBW          .text:  0x802DC98C - 0x802DC9A8
    __mem.c

# cxa.c
# nsmbw-project
    cxa.c

# NSMBW          .text:  0x802DCA70 - 0x802DCAD0
    global_destructor_chain.c

# NSMBW          .text:  0x802DCF3C - 0x802DD5D0
    runtime.c

# cxa.c
# nsmbw-project
    stack_chk.c
)