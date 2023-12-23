# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(systemmonitor)

# Add source files
set(SOURCES
    src/main.cpp
    src/system_monitor.cpp
    src/sender/system_monitor_sender.cpp
    src/reader/system_monitor_reader.cpp
    src/reader/system_monitor_data_reader_linux.cpp
)

# Add header files
set(HEADERS
    h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include
                        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/h)

# Set link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC ptherad)
