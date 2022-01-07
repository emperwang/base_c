# 设置 cmake的版本号
cmake_minimum_required(VERSION 3.14)
project(Cplusplus)

# 设置c++的版本
set(CMAKE_CXX_STANDARD 11)
# 设置c的版本号
# set(CMAKE_C_STANDARD 99)
# 把某个目录中源码存储在一个 变量中
aux_source_directory(. CUR_DIR_SOURCE)

# 设置源码文件,也相当于是设置变量
set(SRC_LIST main.cpp)

# 把某个源文件编译为lib
# add_library(libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] src_list)
# add_library(mylib ${DIR_SOURCE})

# 添加子目录
# add_subdirectory(srcDir [binary_dir] [exclude_from_all])
add_subdirectory(src)
# 生成最终可执行文件时 连接其他的lib
# target_link_libraries(target lib1 lib2)

# 设置输出位置
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# 设置bin文件的输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

# 编译参数
#-DCMAKE_BUILD_TYPE=Debug
#-DCMAKE_MAKE_PROGRAM=D:/ProgramFiles/Cygwin64/bin/make.exe
#-DCMAKE_C_COMPILER=D:/ProgramFiles/Cygwin64/bin/gcc.exe
#DCMAKE_CXX_COMPILER=D:/ProgramFiles/Cygwin64/bin/g++.exe
#-G "CodeBlocks - Unix Makefiles" /cygdrive/e/code-workSpace/project-C/base-C/Cplusplus

# 消息打印
message("this is source dir: " ${CUR_DIR_SOURCE})
message("this is source dir: " ${SRC_LIST})
message("executable output path :" ${PROJECT_BINARY_DIR})
message("library output  path :" ${PROJECT_BINARY_DIR}/lib)
message("project source dir: " ${PROJECT_SOURCE_DIR})
message("cmake_install_prefix :" ${CMAKE_INSTALL_PREFIX})
message("destination :" ${CMAKE_ABSOLUTE_DESTINATION_FILES})
message("destination :" ${DESTINATION})


# 添加头文件
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/hello)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/const)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/static)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/this)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/inline)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/sizeof)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/funcpointer)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/abstruct)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/vptr)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/virtual)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/volatile)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/assert)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/bit_field)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/struct)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/union)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/explicit)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/friend)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/define_use)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/enum
                    ${PROJECT_SOURCE_DIR}/src/operator
                    ${PROJECT_SOURCE_DIR}/src/template
                    ${PROJECT_SOURCE_DIR}/src/exception
                    ${PROJECT_SOURCE_DIR}/src/container
                    ${PROJECT_SOURCE_DIR}/src/encapsulation
                    ${PROJECT_SOURCE_DIR}/src/file)

# 通过变量来设置,添加的头文件是追加到已有路径前
# set(CMAKE_INCLUDE_DIRECTORIES_BEFORE )

# 为target添加共享库
#link_directories(directoyr1 directory2)
link_directories(${PROJECT_SOURCE_DIR}/build/lib)
#target_link_libraries(target library1
#                       <debug|optimized> library2
#                        )

# 上面两个配置还对应两个cmake的环境变量, 注意是环境变量,不是变量
#SET(CMAKE_INCLUDE_PATH )
#SET(CMAKE_LIBRARY_PATH )

# 执行cmake期间执行一些命令
# exec_program(executable [directory in which to run]
#                            [ARGS <argument to executable>]
#                            [OUTPUT_VARIABLE <var>]
#                            [RETURN_VALUE <var>]
#                               )
file(WRITE test "message to write....")

# if 语句
if ("hello" MATCHES "ell")
    message("hello matches ell" )
endif ("hello" MATCHES "ell")

# add_definitions(-DENABLE_DEBUG)

# 添加编译器flag
set(CMAKE_CXX_FLAGS "-std=c++11")

## 添加一个特定的target,用于编译src目录下的源文件
add_custom_target(build_dep ALL
        COMMAND ${CMAKE_MAKE_PROGRAM}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build/src
        COMMENT "build other dependency first")
add_executable(Cplusplus ${SRC_LIST})
# 这里添加依赖,编译可执行文件前,先把build_dep执行完s
add_dependencies(Cplusplus build_dep)


# foreach
foreach(f ${SRC_LIST})
MESSAGE("foreach : " ${f})
endforeach(f)

foreach(VAR RANGE 10)
MESSAGE("FOREACH RANGE " ${VAR})
endforeach(VAR)

# foreach (loop_var RANGE start stop [step])
foreach(A RANGE 5 15 3)
message("foreach range step :" ${A})
endforeach(A)

# find_package 命令
#find_package(<name> [major.minor] [QUITE] [NO_MODULE] [[REQUIRED | COMPONENTS] [components....]])
# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/build/lib)

#find_package(HELLO REQUIRED)
message("hello found: " ${HELLO_FOUND})
MESSAGE("hello_include_dir : ${HELLO_INCLUDE_DIR}")
MESSAGE("hello_library : ${HELLO_LIBRARY}")
if (HELLO_FOUND)
    include_directories(${HELLO_INCLUDE_DIR})
    target_link_libraries(Cplusplus ${HELLO_LIBRARY})
endif (HELLO_FOUND)

# 下面命令是连接动态库
#target_link_libraries(Cplusplus hello)
# 连接静态库
file(GLOB LIB_NAMES ${PROJECT_SOURCE_DIR}/build/lib/*.a)
message(STATUS "find lib_name : ${LIB_NAMES}")
#FOREACH(tname ${LIB_NAMES})
#message(STATUS "lib name: ${tname}")
#ENDFOREACH(tname)

target_link_libraries(Cplusplus ${LIB_NAMES})
#target_link_libraries(Cplusplus libhello.a libconst_num.a libstatic.a libthis.a libinline.a libsizeof.a
#                    libfuncpointer.a libabstruct.a libvptr.a libvirtual.a libvolatile.a libassert.a
#                    libbit_field.a libstruct.a libunion.a libexplicit.a libfriend.a libdefine_use.a
#                    libjenum.a liboperator.a libtemplate.a)

