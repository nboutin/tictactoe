##### Configuration

cmake_minimum_required(VERSION 3.0.0)
project(board_games)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)

##### Sources

add_subdirectory(connect_four)