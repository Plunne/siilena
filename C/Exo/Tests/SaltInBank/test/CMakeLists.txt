include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  UserTest
  user_test.cpp
)

add_executable(
  AccountTest
  account_test.cpp
)

add_executable(
  BankTest
  bank_test.cpp
)

target_link_libraries(
  UserTest
  GTest::gtest_main
  Bank
)

target_link_libraries(
  AccountTest
  GTest::gtest_main
  Bank
)

target_link_libraries(
  BankTest
  GTest::gtest_main
  Bank
)

include(GoogleTest)
gtest_discover_tests(UserTest AccountTest BankTest)





