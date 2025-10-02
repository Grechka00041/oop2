cmake_minimum_required(VERSION 4.0)
project(oop2)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(oop2
        headers/application.h
        headers/array.h
        headers/complex.h
        headers/number.h
        application.cpp
        array.cpp
        complex.cpp
        main.cpp
        polynom.cpp
        headers/polynom.h)
