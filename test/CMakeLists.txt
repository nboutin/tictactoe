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
	${CMAKE_SOURCE_DIR}/source/model
	${CMAKE_SOURCE_DIR}/source/view
	${CMAKE_CURRENT_SOURCE_DIR}/inc
)

##### Sources

set(SOURCE 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_board.cpp
)

##### Target

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(
	${PROJECT_NAME}
	Catch
)

##### Install

#install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_TEST_PATH})
