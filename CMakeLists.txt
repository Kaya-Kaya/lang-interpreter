cmake_minimum_required(VERSION 4.2.0)
project(
    LangInterpreter
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD, 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(interpreter ${SRC_FILES})

target_include_directories(interpreter
    PUBLIC include
)

target_compile_features(interpreter
    PUBLIC cxx_std_23
)

