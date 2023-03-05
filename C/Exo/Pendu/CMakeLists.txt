cmake_minimum_required (VERSION 3.14)
project (Pendu)

set(CMAKE_C_STANDARD 11)

set(HEADERS includes)

add_library(PenduLib
	src/pendu.c
	src/penduio.c
	src/penducheck.c
	src/pendudraw.c
	src/pendufile.c
	src/penduinit.c
)

add_executable (${PROJECT_NAME} main.c)

include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC PenduLib)