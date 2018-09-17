##### Coniguration

cmake_minimum_required(VERSION 3.0.0)
project(tictactoe_test)

##### 3rd party

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

##### Includes

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_SOURCE_DIR}/source/inc
)
include_directories(${CMAKE_SOURCE_DIR}/../ai)

##### Sources

set(SOURCE 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_tictactoe.cpp
	
	${CMAKE_SOURCE_DIR}/source/src/tictactoe.cpp
	${CMAKE_SOURCE_DIR}/source/src/board.cpp
)

##### Compilation

#add_definitions(-Dprivate=public)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=gnu++17")

##### Target

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(
	${PROJECT_NAME}
	Catch
	pthread
)

##### Install

#install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_TEST_PATH})
