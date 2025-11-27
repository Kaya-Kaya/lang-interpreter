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

add_library(interpreter ${SRC_FILES})

target_include_directories(interpreter
    PUBLIC include
)

target_compile_features(interpreter
    PUBLIC cxx_std_23
)

add_executable(lang_run src/main.cpp)
target_link_libraries(lang_run PRIVATE interpreter)

enable_testing()
add_subdirectory(tests)
