cmake_minimum_required(VERSION 3.27)

project(aoc)

add_library(common
        src/common/filehandler.cpp
        src/common/stringparser.cpp
)
target_include_directories(common PUBLIC src/common)

add_executable(2023_day1 src/2023/01/day1.cpp)
target_link_libraries(2023_day1 PRIVATE common)

add_executable(2023_day2 src/2023/02/day2.cpp)
target_link_libraries(2023_day2 PRIVATE common)
