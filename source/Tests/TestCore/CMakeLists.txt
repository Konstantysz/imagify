enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
  TestCore
  TestCore.cpp
)

# Set debugger working directory for compliance with gtest working directory
if (CMAKE_GENERATOR MATCHES "Visual Studio")
	set_target_properties(TestCore PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:TestCore>")
endif()

target_link_libraries(TestCore PRIVATE GTest::gtest_main)
target_link_libraries(TestCore PRIVATE ${OpenCV_LIBS})

include(GoogleTest)
gtest_discover_tests(TestCore)

target_link_libraries(TestCore PUBLIC Core)
target_include_directories(TestCore SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/source/Libraries/")
target_include_directories(TestCore SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/source/Libraries/Core")