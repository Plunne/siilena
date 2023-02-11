cmake_minimum_required(VERSION 3.14)

project(Projet_Langage_C)

set(CMAKE_C_STANDARD 11)

#add_executable(HelloWorld HelloWorld.c)

set (SRC_TEST test.h test.c)

add_library(PrintConsoleLib ${SRC_TEST})

add_executable(prog HelloWorld.c)

target_link_libraries(prog PUBLIC PrintConsoleLib)