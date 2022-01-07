aux_source_directory(. SRC_EXTERN)
message(STATUS "building extern lib..${SRC_EXTERN}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(extern SHARED ${SRC_EXTERN})
add_library(extern_sta STATIC ${SRC_EXTERN})
set_target_properties(extern_sta PROPERTIES OUTPUT_NAME "extern")
