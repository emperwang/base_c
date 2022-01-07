aux_source_directory(. SRC_SIZEOF)
message(STATUS "build sizeof lib: ${SRC_SIZEOF} ")


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(sizeof SHARED ${SRC_SIZEOF})
add_library(sizeof_sta STATIC ${SRC_SIZEOF})
set_target_properties(sizeof_sta PROPERTIES OUTPUT_NAME "sizeof")

