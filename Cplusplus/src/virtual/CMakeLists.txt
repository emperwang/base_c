aux_source_directory(. SRC_VIRTUAL)

message(STATUS "Building virtual .. ${SRC_VIRTUAL}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(virtual SHARED ${SRC_VIRTUAL})
add_library(virtual_sta STATIC ${SRC_VIRTUAL})
set_target_properties(virtual_sta PROPERTIES OUTPUT_NAME "virtual")


