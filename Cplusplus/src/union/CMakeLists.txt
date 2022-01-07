aux_source_directory(. SRC_UNION)
MESSAGE(STATUS "build union.. ${SRC_UNION}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(union SHARED ${SRC_UNION})
add_library(union_sta STATIC ${SRC_UNION})
set_target_properties(union_sta PROPERTIES OUTPUT_NAME "union")
