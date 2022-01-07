aux_source_directory(. SRC_FILE_HANDLE)

message(STATUS "building lib file handle ${SRC_FILE_HANDLE}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(file_handle SHARED ${SRC_FILE_HANDLE})
add_library(file_handle_sta STATIC ${SRC_FILE_HANDLE})

set_target_properties(file_handle_sta PROPERTIES OUTPUT_NAME "file_handle")

