aux_source_directory(. SRC_ENUM)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(jenum SHARED ${SRC_ENUM})
add_library(jenum_sta STATIC ${SRC_ENUM})
set_target_properties(jenum_sta PROPERTIES OUTPUT_NAME "jenum")


