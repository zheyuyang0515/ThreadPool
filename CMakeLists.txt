cmake_minimum_required(VERSION 3.16)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 14)

add_executable(ThreadPool main.cpp Task.cpp Task.h ThreadPool.cpp ThreadPool.h Logger.h)

target_link_libraries(ThreadPool pthread)
target_link_libraries(ThreadPool glog)