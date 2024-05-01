cmake_minimum_required(VERSION 3.15.0)

project(LAB_04_220220)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp
Money.cpp)

set(HEADER_FILES Money.h Set.h)

set(ALL_SOURCES ${HEADER_FILSE}
				${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${ALL_SOURCES})