find_package(Git QUIET)

set(MKWCAT_VERSION "edit")

if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --tags --dirty --abbrev=0
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE latest_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE result
    )

    if(result EQUAL 0)
        set(MKWCAT_VERSION "${latest_tag}")
    endif()
endif()


add_custom_target(mkwcat-nsmbw.xml
    ALL
    DEPENDS loader "${CMAKE_SOURCE_DIR}/riivolution/mkwcat-nsmbw.xml" "${INSERTXML}"
    COMMENT "Generating mkwcat-nsmbw.xml"
    COMMAND python ${INSERTXML} "${CMAKE_SOURCE_DIR}/riivolution/mkwcat-nsmbw.xml" "${CMAKE_BINARY_DIR}/loader/loader.elf" "${MKWCAT_VERSION}" "${CMAKE_BINARY_DIR}/riivolution/mkwcat-nsmbw.xml"
)
