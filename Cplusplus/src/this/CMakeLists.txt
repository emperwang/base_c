aux_source_directory(. SRC_THIS)
# STATUS 输出信息
# SEND_ERROR 产出错误,生成过程被跳过
# FATAL_ERROR 立即终止所有cmake过程
message(STATUS "build this lib .. ${SRC_THIS}")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(this SHARED ${SRC_THIS})
add_library(this_sta STATIC ${SRC_THIS})
set_target_properties(this_sta PROPERTIES OUTPUT_NAME "this")

