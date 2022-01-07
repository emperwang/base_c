aux_source_directory(. SRC_FUNC_POINTER)

message(STATUS "build func pointer lib ${SRC_FUNC_POINTER}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(funcpointer SHARED ${SRC_FUNC_POINTER})
add_library(funcpointer_sta STATIC ${SRC_FUNC_POINTER})
set_target_properties(funcpointer_sta PROPERTIES OUTPUT_NAME "funcpointer")


