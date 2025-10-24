cmake_minimum_required(VERSION 3.23)

include(ExternalProject)

project(llvm-project)

ExternalProject_Add(
    llvm-project
    PREFIX llvm-project
    BINARY_DIR "${CMAKE_BINARY_DIR}/llvm-project"
    GIT_REPOSITORY https://github.com/mkwcat/llvm-project.git
    GIT_TAG release-19-with-cw
    SOURCE_SUBDIR llvm
    CMAKE_ARGS ${CMAKE_ARGS}
        -DCMAKE_BUILD_TYPE=Release
        -DLLVM_BUILD_TOOLS=OFF
        -DLLVM_ENABLE_PROJECTS=clang
        -DLLVM_TARGETS_TO_BUILD=PowerPC
        -DLLVM_DEFAULT_TARGET_TRIPLE=powerpc-gekko-ibm-kuribo-eabi
        -DLLVM_ENABLE_THREADS=OFF
        -DLLVM_ENABLE_ZLIB=OFF
        -DLLVM_ENABLE_LIBXML2=OFF
        -DLLVM_ENABLE_UNWIND_TABLES=OFF
        -DLLVM_INCLUDE_BENCHMARKS=OFF
        -DLLVM_INCLUDE_EXAMPLES=OFF
        -DLLVM_INCLUDE_TESTS=OFF
        -DLLVM_INCLUDE_TOOLS=ON
        -DCLANG_DEFAULT_LINKER=lld
    BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --target clang
    INSTALL_COMMAND ${CMAKE_COMMAND} -E copy <BINARY_DIR>/bin/clang${CMAKE_HOST_EXECUTABLE_SUFFIX} ${CMAKE_SOURCE_DIR}
    USES_TERMINAL_DOWNLOAD true
    USES_TERMINAL_UPDATE true
    USES_TERMINAL_BUILD true
    USES_TERMINAL_INSTALL true
    USES_TERMINAL_TEST true
)