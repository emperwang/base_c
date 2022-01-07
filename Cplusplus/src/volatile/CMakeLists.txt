aux_source_directory(. SRC_VOLATILE)

message(STATUS "build volatile lib... ${SRC_VOLATILE}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(volatile SHARED ${SRC_VOLATILE})
add_library(volatile_sta STATIC ${SRC_VOLATILE})

set_target_properties(volatile_sta PROPERTIES OUTPUT_NAME "volatile")
