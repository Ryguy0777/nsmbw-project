add_executable(project "")

target_compile_options(project PRIVATE
    -include System.h
    -fstack-protector-all
)

target_link_options(project PRIVATE
    -T "${CMAKE_SOURCE_DIR}/source/Module.ld"
    -r
    -Wl,--force-group-allocation
)

file(GLOB_RECURSE C_SOURCE_FILES "${CMAKE_SOURCE_DIR}/*.c")
set_source_files_properties(${C_SOURCE_FILES} PROPERTIES LANGUAGE CXX)

target_sources(project PRIVATE
# Note: Uppercase letters are always sorted before lowercase

# Root source files
    Module.cpp
    Four.cpp
)


add_subdirectory(wiimj2d)
add_subdirectory(revolution)
add_subdirectory(nw4r)
add_subdirectory(egg)
add_subdirectory(msl)


# #
# # egg/math
# #

# # NSMBW          .text:  0x802BE760 - 0x802BE820
#     egg/math/eggMath.cpp

# #
# # egg/gfx
# #

# # NSMBW          .text:  0x802D0D90 - 0x802D2060
#     egg/gfx/eggScreen.cpp

# #
# # egg/util
# #

# # NSMBW          .text:  0x802D7D90 - 0x802D8BC0
#     egg/util/eggEffect.cpp

# #
# # msl/runtime
# #

# # NSMBW          .init:  0x80004364 - 0x800046E4
# # NSMBW          .text:  0x802DC98C - 0x802DC9A8
#     msl/runtime/__mem.c

# # cxa.c
# # nsmbw-project
#     msl/runtime/cxa.c

# # NSMBW          .text:  0x802DCA70 - 0x802DCAD0
#     msl/runtime/global_destructor_chain.c

# # NSMBW          .text:  0x802DCF3C - 0x802DD5D0
#     msl/runtime/runtime.c

# # stack_chk.c
# # nsmbw-project
#     msl/runtime/stack_chk.c

# #
# # PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src
# #

# # NSMBW          .text:  0x802DEC0C - 0x802DEDFC
#     msl/c/file_io.c

# # NSMBW          .text:  0x802DF06C - 0x802DF264
#     msl/c/mbstring.c
# # NSMBW          .text:  0x802DF264 - 0x802DF3D4
#     msl/c/mem.c

# # NSMBW          .text:  0x802DF7A8 - 0x802E1BA0
#     msl/c/printf.c
# # NSMBW          .text:  0x802E1BA0 - 0x802E1C28
#     msl/c/scanf.c
# # NSMBW          .text:  0x802E1C28 - 0x802E4FC8
#     msl/c/string.c
# # NSMBW          .text:  0x802E1FE4 - 0x802E24BC
#     msl/c/strtoul.c

# # NSMBW          .text:  0x802E47E8 - 0x802E4860
#     msl/c/wchar_io.c

# #
# # PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision
# #

# # NSMBW .text: 0x802E8B58 - 0x802E8B5C
#     msl/c/math/w_sqrt.c

