include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(unit_tests
    test_number.cpp
    test_bool.cpp
    test_context.cpp
)
target_link_libraries(unit_tests PRIVATE gtest_main interpreter_lib)
include(GoogleTest)
gtest_discover_tests(unit_tests)