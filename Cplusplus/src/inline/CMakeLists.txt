aux_source_directory(. SRC_INLINE)
message(STATUS "building inline ${SRC_INLINE}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(inline SHARED ${SRC_INLINE})
add_library(inline_sta STATIC ${SRC_INLINE})
set_target_properties(inline_sta PROPERTIES OUTPUT_NAME "inline")

