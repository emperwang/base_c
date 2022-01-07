aux_source_directory(. SRC_TEMPLATE)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
ADD_LIBRARY(template SHARED ${SRC_TEMPLATE})
ADD_LIBRARY(template_sta STATIC ${SRC_TEMPLATE})

set_target_properties(template_sta PROPERTIES OUTPUT_NAME "template")

