# Add test sources
set(TEST_SOURCES
    test.cpp
)

# Get all source files
set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/src/NCursesSession.cpp
    ${PROJECT_SOURCE_DIR}/src/Window.cpp
)

# Create test executable
add_executable(${PROJECT_NAME}_test 
    ${TEST_SOURCES} 
    ${PROJECT_SOURCES}
)

# Include directories
target_include_directories(${PROJECT_NAME}_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Link dependencies
target_link_libraries(${PROJECT_NAME}_test
    PRIVATE
    ${CURSES_LIBRARIES}
)

# Add test
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
