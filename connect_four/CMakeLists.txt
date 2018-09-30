##### Configuration

cmake_minimum_required(VERSION 3.0.0)
project(connect_four)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)

##### Source

add_subdirectory(source)

##### Test

add_subdirectory(test)
