cmake_minimum_required(VERSION 4.2.0)
project(
    LangInterpreter
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(ABSL_ENABLE_INSTALL ON)
FetchContent_Declare(
    absl
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG        20250814.1
)
FetchContent_MakeAvailable(absl)

FetchContent_Declare(
    re2
    GIT_REPOSITORY https://github.com/google/re2.git
    GIT_TAG        2025-11-05
)
FetchContent_MakeAvailable(re2)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

list(FILTER SRC_FILES EXCLUDE REGEX "src/main.cpp$")

add_library(interpreter_lib ${SRC_FILES})
target_link_libraries(interpreter_lib PRIVATE re2::re2)

target_include_directories(interpreter_lib
    PUBLIC include
)

target_compile_features(interpreter_lib
    PUBLIC cxx_std_23
)

add_executable(interpreter src/main.cpp)
target_link_libraries(interpreter PRIVATE interpreter_lib)

enable_testing()
add_subdirectory(tests)
