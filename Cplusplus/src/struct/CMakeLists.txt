aux_source_directory(. SRC_STRUCT)

message(STATUS "building struct lib..${SRC_STRUCT}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(struct SHARED ${SRC_STRUCT})
add_library(struct_sta STATIC ${SRC_STRUCT})
set_target_properties(struct_sta PROPERTIES OUTPUT_NAME "struct")