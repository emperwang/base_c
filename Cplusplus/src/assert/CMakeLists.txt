aux_source_directory(. SRC_ASSERT)
message(STATUS "building assert lib .. ${SRC_ASSERT}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(assert SHARED ${SRC_ASSERT})
add_library(assert_sta STATIC ${SRC_ASSERT})
set_target_properties(assert_sta PROPERTIES OUTPUT_NAME "assert")

