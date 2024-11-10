set(TEST_SOURCES
    test.cpp
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Create test exe
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})

# Add test
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
