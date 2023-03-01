cmake_minimum_required (VERSION 3.14)
project (Structures)

set(CMAKE_C_STANDARD 11)

set(HEADERS includes)

add_library(Structures2 src/structures.c)

add_executable (${PROJECT_NAME} main.c)

include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC Structures2)