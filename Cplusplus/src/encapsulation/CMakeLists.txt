aux_source_directory(. SRC_ENCAPSULATION)

MESSAGE(STATUS "building lib encapsulation ${SRC_ENCAPSULATION}")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
ADD_LIBRARY(encapsulation SHARED ${SRC_ENCAPSULATION})
ADD_LIBRARY(encapsulation_sta STATIC ${SRC_ENCAPSULATION})

set_target_properties(encapsulation_sta PROPERTIES OUTPUT_NAME "encapsulation")
