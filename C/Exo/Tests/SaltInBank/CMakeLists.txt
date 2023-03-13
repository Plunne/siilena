project(SaltInBank)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)

add_library(Bank bank.h bank.c user.h user.c account.h account.c)

add_subdirectory(test)

add_executable(BankSoftware main.c)

target_link_libraries(BankSoftware PUBLIC Bank)

