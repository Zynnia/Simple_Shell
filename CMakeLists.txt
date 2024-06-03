cmake_minimum_required(VERSION 3.28)
project(Simple_Shell)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Simple_Shell
        cpu.h
        interpreter.h
        kernel.cpp
        kernel.h
        pcb.h
        ram.h
        shell.h
        shellmemory.h)
