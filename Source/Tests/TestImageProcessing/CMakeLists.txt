enable_testing()

add_executable(
  TestImageProcessing
  TestImageProcessing.cpp
)
target_link_libraries(TestImageProcessing PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestImageProcessing)

target_link_libraries(TestImageProcessing PUBLIC ImageProcessing)
target_include_directories(TestImageProcessing SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/Source/Libraries/")
target_include_directories(TestImageProcessing SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/Source/Libraries/ImageProcessing")