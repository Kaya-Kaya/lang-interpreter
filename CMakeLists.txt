cmake_minimum_required(VERSION 4.2.0)
project(
    LangInterpreter
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD, 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

list(FILTER SRC_FILES EXCLUDE REGEX "src/main.cpp$")

add_library(interpreter_lib ${SRC_FILES})

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
