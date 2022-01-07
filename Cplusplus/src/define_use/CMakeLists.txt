aux_source_directory(. SRC_DEFINE)
MESSAGE(STATUS "building define lib...${SRC_DEFINE}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(define_use SHARED ${SRC_DEFINE})
add_library(define_use_sta STATIC ${SRC_DEFINE})
set_target_properties(define_use_sta PROPERTIES OUTPUT_NAME "define_use")
