enable_testing()

add_executable(
    TestCore
    TestCore.cpp
)
target_link_libraries(
    TestCore
    GTest::gtest_main
)

set_target_properties(TestCore PROPERTIES FOLDER Tests)

include(GoogleTest)
gtest_discover_tests(TestCore)