cmake_minimum_required(VERSION 3.17)
project(libcsv)

set(CMAKE_CXX_STANDARD 17)

add_executable(libcsv main.cpp csv.cpp csv.h)