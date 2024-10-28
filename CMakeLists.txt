cmake_minimum_required(VERSION 3.22.1)
project(Simple_Shell)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Simple_Shell
        include/interpreter.h
        include/pcb.h
        kernel.cpp
        include/kernel.h
        include/ram.h
        include/shell.h
        include/shellmemory.h
        interpreter.cpp
        shell.cpp
        include/cpu.h
        memorymanager.cpp
        include/memorymanager.h
        ram.cpp
)
