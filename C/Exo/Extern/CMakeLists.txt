cmake_minimum_required (VERSION 3.14)
project (Modify)

set(CMAKE_C_STANDARD 11)

set(HEADERS includes)
set(SOURCES src/modifX.c src/modifY.c)

add_library(ModifyLib ${SOURCES})

add_executable (${PROJECT_NAME} main.c)

include_directories(${PROJECT_NAME} PUBLIC ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC ModifyLib)