aux_source_directory(. SRC_CONST)
message("build const num........ ${SRC_CONST}")

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(const_num SHARED ${SRC_CONST})
add_library(const_num_static STATIC ${SRC_CONST})
set_target_properties(const_num_static PROPERTIES OUTPUT_NAME "const_num")



