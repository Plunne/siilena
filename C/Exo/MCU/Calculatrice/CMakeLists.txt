cmake_minimum_required (VERSION 3.14)
project (Calculatrice)

set(CMAKE_C_STANDARD 11)

set(SOURCES calc.c)
set(HEADERS calc.h io.h)

add_library(Console console.c)
add_library(File file.c)

add_executable (Calculatrice main.c ${SOURCES} ${HEADERS})

target_link_libraries(Calculatrice PUBLIC File)