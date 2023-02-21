cmake_minimum_required (VERSION 3.14)
project (HELLO)

set(CMAKE_C_STANDARD 11)

set(SOURCES src/morse_audio.c src/morse_beep.c src/morse_code.c)

add_executable (Hello main.c ${SOURCES})

target_include_directories (Hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
