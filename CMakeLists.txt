# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project name
project(systemmonitor)

# Add source files
set(SOURCES
    src/main.cpp
    src/utils.cpp
    src/monitor.cpp
)

# Add header files
set(HEADERS
    include/utils.h
    include/monitor.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include)
