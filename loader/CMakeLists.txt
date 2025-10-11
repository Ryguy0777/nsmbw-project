add_executable(loader Loader.cpp)

target_link_options(loader PRIVATE
    -T${CMAKE_SOURCE_DIR}/loader/Loader.ld
    -Wl,--no-dynamic-linker
    -static
)
