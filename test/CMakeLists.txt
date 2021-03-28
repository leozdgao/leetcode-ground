enable_testing()

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_executable(test
    ../src/t01.cc t01_test.cc
    ../src/t04.cc t04_test.cc
    ../src/t05.cc t05_test.cc
)
find_package(GTest CONFIG REQUIRED)
target_link_libraries(test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

# work with ctest
include(GoogleTest)
gtest_discover_tests(test)
