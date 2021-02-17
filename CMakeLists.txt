cmake_minimum_required(VERSION 3.12)
project(hm3301_driver)

set(CMAKE_C_STANDARD 90)

add_library(hm3301 hm3301.c)
target_include_directories(hm3301 PUBLIC /usr/include/)
target_link_libraries(hm3301 -li2c)

add_executable(measure main.c)
target_link_libraries(measure hm3301)
