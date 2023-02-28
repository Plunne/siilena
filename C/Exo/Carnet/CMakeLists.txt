cmake_minimum_required (VERSION 3.14)

project (Carnet)

set(CMAKE_C_STANDARD 11)

set(HEADERS includes/)

add_library(LibCarnet src/carnet.c src/carnet_init.c)

add_executable (${PROJECT_NAME} main.c)

include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC LibCarnet)