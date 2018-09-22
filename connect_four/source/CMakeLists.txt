##### Configuration

cmake_minimum_required(VERSION 3.0.0)
project(connect_four)

##### 3rd party

##### Include

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ai)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external)

##### Source

set(SOURCE
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/connect4.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/view_ascii.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ai/minmax.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ai/evaluate.cpp
)

##### Compilation

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=gnu++17")

##### Target

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
	pthread
)

##### Install

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

