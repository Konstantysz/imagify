set(TARGET Imagify)

if (DEFINED ENV_WX_CONFIG)
    set (ENV{WX_CONFIG ${ENV_WX_CONFIG}})
endif()

find_package(wxWidgets REQUIRED)
find_package(OpenCV REQUIRED)

include(${wxWidgets_USE_FILE})
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB ImagifyGUISource
     "*.h"
     "*.cpp"
)

if (APPLE)
    add_executable(${TARGET} MACOSX_BUNDLE ${ImagifyGUISource})
else()
    add_executable(${TARGET} WIN32 ${ImagifyGUISource})
endif()

target_link_libraries(${TARGET} PRIVATE ${wxWidgets_LIBRARIES})
target_link_libraries(${TARGET} PRIVATE ${OpenCV_LIBS})