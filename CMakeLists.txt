cmake_minimum_required(VERSION 3.28)
project(Simple_Shell)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Simple_Shell
        interpreter.h
        pcb.h
        kernel.cpp
        kernel.h
        ram.h
        shell.h
        shellmemory.h
        interpreter.cpp
        shell.cpp
        cpu.h
)
