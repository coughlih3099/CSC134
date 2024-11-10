cmake_minimum_required(VERSION 3.10)
project(FinalProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build to debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Find ncurses
find_package(Raylib REQUIRED)

# add source files
set(SOURCES
    src/main.cpp
    src/Window.cpp
)

# Add include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${RAYLIB_INCLUDE_DIR}
)

# Create main executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against ncurses
target_link_libraries(
    ${PROJECT_NAME} PRIVATE ${RAYLIB_LIBRARIES}
)

# Testing setup
enable_testing()
add_subdirectory(test)
