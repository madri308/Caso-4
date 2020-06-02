cmake_minimum_required(VERSION 3.16)
project(lineas)

set(CMAKE_CXX_STANDARD 14)

add_executable(lineas main.cpp cmake-build-debug/getNumbersInScreen.cpp cmake-build-debug/getNumbersInScreen.h)