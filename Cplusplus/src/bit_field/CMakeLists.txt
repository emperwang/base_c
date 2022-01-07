aux_source_directory(. SRC_BIT_FIELD)
MESSAGE(STATUS "build bit field ${SRC_BIT_FIELD}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(bit_field SHARED ${SRC_BIT_FIELD})
add_library(bit_field_sta STATIC ${SRC_BIT_FIELD})
set_target_properties(bit_field_sta PROPERTIES OUTPUT_NAME "bit_field")
