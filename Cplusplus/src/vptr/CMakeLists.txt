aux_source_directory(. SRC_VPTR)
message(STATUS "building vptr lib ${SRC_VPTR}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(vptr SHARED ${SRC_VPTR})
add_library(vptr_sta STATIC ${SRC_VPTR})
set_target_properties(vptr_sta PROPERTIES OUTPUT_NAME "vptr")

