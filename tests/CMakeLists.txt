# Enable testing
enable_testing()

# Create test executable
add_executable(TaskManagerTests
    tests/test_main.cpp
    tests/TaskManagerTests.cpp
)

# Link with GoogleTest (assuming installed through package manager)
find_package(GTest REQUIRED)
target_link_libraries(TaskManagerTests PRIVATE GTest::gtest GTest::gtest_main pthread)

# Register the test with CTest
add_test(NAME TaskManagerTests COMMAND TaskManagerTests)
