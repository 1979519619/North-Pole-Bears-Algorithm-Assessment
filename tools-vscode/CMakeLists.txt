cmake_minimum_required(VERSION 3.20)

project(temperature_converter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(temperature_converter src/main.cpp)
