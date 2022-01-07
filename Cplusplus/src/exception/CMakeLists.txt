aux_source_directory(. SRC_EXCEPTION)

message(STATUS "build lib exception : ${SRC_EXCEPTION}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(exception SHARED ${SRC_EXCEPTION})
add_library(exception_sta STATIC ${SRC_EXCEPTION})
set_target_properties(exception_sta PROPERTIES OUTPUT_NAME "exception")
