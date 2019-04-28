cmake_minimum_required(VERSION 3.13)
project(review)

set(CMAKE_CXX_STANDARD 14)

include_directories(${review_SOURCE_DIR}/include)
add_subdirectory(src)

add_executable(review main.cc include/tree.h)
target_link_libraries(review lib)