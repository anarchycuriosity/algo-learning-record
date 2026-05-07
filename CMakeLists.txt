cmake_minimum_required(VERSION 3.10)
project(hfut_cpp_project)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出路径：将可执行文件放入 bin 目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/inc)

# 寻找 src 下的所有源文件
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# 生成可执行文件（这里假设生成一个固定的 main.exe）
# 如果你习惯一个文件一个 exe，建议每个练习建立独立的子文件夹
add_executable(main ${SRC_FILES})

# 开启所有警告并包含调试信息
target_compile_options(main PRIVATE -Wall -g)