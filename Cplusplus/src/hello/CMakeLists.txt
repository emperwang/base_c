aux_source_directory(.  LIB_SRC)
message("build hello dynamic lib." ${LIB_SRC})

# 设置library 输出的位置
set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build/lib)
add_library(hello SHARED ${LIB_SRC})
set_target_properties(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#set_target_properties(hello PROPERTIES VERSION 1.2 SOVERSION 1)

add_library(hello_static STATIC ${LIB_SRC})
set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello")
set_target_properties(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 获取properties属性值
get_target_property(OUTPUT_VALUE hello_static OUTPUT_NAME)
message("output_value :" ${OUTPUT_VALUE})
#
message("cmake_current_list_file: " ${CMAKE_CURRENT_LIST_FILE})
MESSAGE("cmake_current_list_line:" ${CMAKE_CURRENT_LIST_LINE})
MESSAGE("cmake_current_list_dir:" ${CMAKE_CURRENT_LIST_DIR})

# message 调用环境变量的值
MESSAGE("env varabile: " $ENV{HOME})

# 设置生成的库为动态库, 默认生成的库为静态
# SET(BUILD_SHARED_LIBS  ON)

# 设置c 或者 c++的编译选项
## 方式一 通过变量设置
#set(CMAKE_C_FLAGS )
#set(CMAKE_CXX_FLAGS )
##方式二 通过方法添加
# ADD_DEFINITIONS(-DENABLE_DEBUG  -DABC)
# -DENABLE_DEBUG情况下, 如果代码中定义了 #ifdef ENABLE_DEBUG #endif 会立即生效

# 定义依赖
# add_dependencies(target depend1 depend2)

# 安装文件
# install(TARGETS hello hello_static
#       LIBRARY  DESTINATION hello
#       ARCHIVE  DESTINATION hello
#       )

# install(FILES hello.h DESTINATION include/hello)


