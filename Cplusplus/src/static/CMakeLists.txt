aux_source_directory(. SRC_STATIC)
message(STATUS "build static lib : ${SRC_STATIC}")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(static SHARED ${SRC_STATIC})
add_library(static_sta STATIC ${SRC_STATIC})
set_target_properties(static_sta PROPERTIES OUTPUT_NAME "static")



