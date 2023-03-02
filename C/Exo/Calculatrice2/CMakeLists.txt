cmake_minimum_required (VERSION 3.14)
project (Calculatrice2)

set(CMAKE_C_STANDARD 11)

set(HEADERS includes)

add_library(Operator src/calcope.c)
add_library(CalcLib src/calclib.c)
add_library(Arithmetic src/calcarith.c)
add_library(Comparaison src/calccmp.c)
add_library(CalcIO src/calcio.c)
add_library(File src/file.c)

add_executable (${PROJECT_NAME} main.c)

include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC Operator CalcLib Arithmetic Comparaison CalcIO)