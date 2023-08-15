cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Add your source files
set(SOURCES
    src/main.c
    src/main.cpp
    src/utils.c
)

# Set C++ standard (for .cpp files)
set(CMAKE_CXX_STANDARD 11)

# Generate separate executables for C and C++ sources
add_executable(main_c ${SOURCES})
add_executable(main_cpp ${SOURCES})

# Set output directories for the executables
set_target_properties(main_c PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set_target_properties(main_cpp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
