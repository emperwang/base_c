aux_source_directory(.  SRC_OPERATOR)

message(STATUS "build operator lib..${SRC_OPERATOR}")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(operator SHARED ${SRC_OPERATOR})
add_library(operator_sta STATIC ${SRC_OPERATOR})
set_target_properties(operator_sta PROPERTIES OUTPUT_NAME "operator")