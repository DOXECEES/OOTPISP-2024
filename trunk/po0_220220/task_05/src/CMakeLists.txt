cmake_minimum_required(VERSION 3.15.0)

project(LAB_05_220220)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp
Cash.cpp)

set(HEADER_FILES Cash.h Set.h SSet.h)

set(ALL_SOURCES ${HEADER_FILSE}
				${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${ALL_SOURCES})