cmake_minimum_required(VERSION 3.14)

project(LeetCodeGround VERSION 1.0)

# message(STATUS "This is Binary dir " ${CMAKE_BINARY_DIR})
# message(STATUS "This is Source dir " ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 添加核心源码目录
add_subdirectory(src bin)
# 添加辅助模块目录
add_subdirectory(lib)
# 添加测试目录
add_subdirectory(test)
