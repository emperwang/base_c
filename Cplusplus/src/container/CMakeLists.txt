aux_source_directory(. SRC_CONTAINER)
MESSAGE(STATUS "build container lib: ${SRC_CONTAINER}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(container SHARED ${SRC_CONTAINER})
add_library(container_sta STATIC ${SRC_CONTAINER})
set_target_properties(container_sta PROPERTIES OUTPUT_NAME "container")
