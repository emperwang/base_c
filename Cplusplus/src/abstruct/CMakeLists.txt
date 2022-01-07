aux_source_directory(. SRC_ABSTRUCT)

message(STATUS "build abstruct lib ${SRC_ABSTRUCT}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(abstruct SHARED ${SRC_ABSTRUCT})
add_library(abstruct_sta STATIC ${SRC_ABSTRUCT})
set_target_properties(abstruct_sta PROPERTIES OUTPUT_NAME "abstruct")



