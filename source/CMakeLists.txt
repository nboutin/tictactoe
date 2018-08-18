##### Configuration

cmake_minimum_required(VERSION 3.0.0)
project(p4)

##### 3rd party

##### Include

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/model)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/view)

##### Source

set(SOURCE
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/model/cell.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/model/board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/view/view_ascii.cpp
)

##### Compilation

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=gnu++17")

##### Target

add_executable(${PROJECT_NAME} ${SOURCE})

##### Install

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

