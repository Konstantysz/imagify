cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

if (DEFINED ENV_WX_CONFIG)
    set (ENV{WX_CONFIG ${ENV_WX_CONFIG}})
endif()

find_package(wxWidgets REQUIRED)
find_package(OpenCV REQUIRED)

include(${wxWidgets_USE_FILE})
include_directories(${OpenCV_INCLUDE_DIRS})

if (APPLE)
    add_executable(Imagify MACOSX_BUNDLE Imagify.cpp)
else()
    add_executable(Imagify WIN32 Imagify.cpp)
endif()

target_link_libraries(Imagify PRIVATE ${wxWidgets_LIBRARIES})
target_link_libraries(Imagify PRIVATE ${OpenCV_LIBS})