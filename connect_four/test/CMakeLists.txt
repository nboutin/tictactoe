##### Coniguration

cmake_minimum_required(VERSION 3.0.0)
project(p4_test)

##### 3rd party

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

##### Includes

include_directories(
	${CMAKE_SOURCE_DIR}/connect_four/source/inc
	${CMAKE_SOURCE_DIR}/connect_four/source/src/model
	${CMAKE_SOURCE_DIR}/connect_four/source/src/view
	${CMAKE_SOURCE_DIR}/connect_four/source/src/ai
	
	${CMAKE_CURRENT_SOURCE_DIR}/inc
)

##### Sources

set(SOURCE 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_cell.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_evaluate.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_minmax.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_game_p4.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_bug.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_perf.cpp
	
	${CMAKE_SOURCE_DIR}/connect_four/source/src/model/board.cpp
	${CMAKE_SOURCE_DIR}/connect_four/source/src/model/cell.cpp
	${CMAKE_SOURCE_DIR}/connect_four/source/src/view/view_ascii.cpp
	${CMAKE_SOURCE_DIR}/connect_four/source/src/game_p4.cpp
	${CMAKE_SOURCE_DIR}/connect_four/source/src/player.cpp
	${CMAKE_SOURCE_DIR}/connect_four/source/src/ai/minmax.cpp
	${CMAKE_SOURCE_DIR}/connect_four/source/src/ai/evaluate.cpp
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
