# Add GTest and GMock
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_target_properties(gmock PROPERTIES FOLDER Thirdparty/googletest)
set_target_properties(gmock_main PROPERTIES FOLDER Thirdparty/googletest)
set_target_properties(gtest PROPERTIES FOLDER Thirdparty/googletest)
set_target_properties(gtest_main PROPERTIES FOLDER Thirdparty/googletest)

# Add OpenCV
# find_package(OpenCV REQUIRED)

# Add subdirectories
add_subdirectory(Imagify)
add_subdirectory(Libraries)
add_subdirectory(Tests)