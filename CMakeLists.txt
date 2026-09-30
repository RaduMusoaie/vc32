cmake_minimum_required(VERSION 3.20)

project(vc32
    VERSION 1.0
    LANGUAGES C CXX
)

# C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# C libraries

add_library(core
    src/core/cpu.cpp)

# includes

target_include_directories(core
    PUBLIC
        $(PROJECT_SOURCE_DIR)/include)

# main

add_executable(app 
    src/app/main.cpp)

target_include_directories(app
PUBLIC
    $(PROJECT_SOURCE_DIR)/include)
