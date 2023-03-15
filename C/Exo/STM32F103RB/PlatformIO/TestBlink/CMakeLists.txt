project(TestBlink)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)

set(INCS
    include/lsl_pinouts.h
    include/lsl_init_regs.h
    include/lsl_utils.h
    include/lsl_display.h
    include/main.h
    include/STM32F103_TestDriver.h
)

set(SRCS
    src/lsl_pinouts.c
    src/lsl_init_regs.c
    src/lsl_delay.c
    src/lsl_display.c
)

add_library(LibSTM32 ${SRCS} ${INCS})


target_compile_definitions(LibSTM32 PUBLIC TESTING)


add_subdirectory(test)


#add_executable(${PROJECT_NAME} src/main.c)

target_include_directories(LibSTM32 PUBLIC ${CMAKE_SOURCE_DIR}/include)

#target_link_libraries(${PROJECT_NAME} PUBLIC LibSTM32)