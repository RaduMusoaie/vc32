cmake_minimum_required(VERSION 3.20)

project(vc32
    VERSION 1.0
    LANGUAGES C CXX
)

# C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# core lib

add_library(core
    src/core/cpu.cpp)

target_include_directories(core
    PUBLIC
        $(PROJECT_SOURCE_DIR)/include)

    
# main application

add_executable(app 
    src/app/main.cpp)

target_link_libraries(app
    PRIVATE
        core)

# tests

enable_testing()

add_executable(cpu_tests
    tests/cpu_test.cpp)

target_link_libraries(cpu_tests
    PRIVATE
        core)

add_test(
    NAME cpu_tests
    COMMAND cpu_tests
)


