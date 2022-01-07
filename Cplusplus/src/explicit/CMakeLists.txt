aux_source_directory(. SRC_EXPLICIT)
MESSAGE(STATIC "Building explicit ${SRC_EXPLICIT}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(explicit SHARED ${SRC_EXPLICIT})
add_library(explicit_sta STATIC ${SRC_EXPLICIT})
set_target_properties(explicit_sta PROPERTIES OUTPUT_NAME "explicit")
