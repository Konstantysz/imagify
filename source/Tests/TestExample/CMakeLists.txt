enable_testing()

add_executable(
    TestExample
    TestExample.cpp
)
target_link_libraries(
    TestExample
    GTest::gtest_main
)

set_target_properties(TestExample PROPERTIES FOLDER Tests)

include(GoogleTest)
gtest_discover_tests(TestExample)