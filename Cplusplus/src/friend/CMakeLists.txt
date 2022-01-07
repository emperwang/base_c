aux_source_directory(. SRC_FRIEND)
MESSAGE(STATUS "building friend lib.. ${SRC_FRIEND}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(friend SHARED ${SRC_FRIEND})
add_library(friend_sta STATIC ${SRC_FRIEND})
set_target_properties(friend_sta PROPERTIES OUTPUT_NAME "friend")

