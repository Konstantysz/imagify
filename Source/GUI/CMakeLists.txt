if (DEFINED ENV_WX_CONFIG)
    set (ENV{WX_CONFIG ${ENV_WX_CONFIG}})
endif()

find_package(wxWidgets REQUIRED)

include(${wxWidgets_USE_FILE})

file(GLOB ImagifyGUISource
     "*.h"
     "*.cpp"
)

if (APPLE)
    add_executable(ImagifyGUI MACOSX_BUNDLE ${ImagifyGUISource})
else()
    add_executable(ImagifyGUI WIN32 ${ImagifyGUISource})
endif()

target_link_libraries(ImagifyGUI PUBLIC ${wxWidgets_LIBRARIES})

target_link_libraries(ImagifyGUI PUBLIC ImageProcessing)
target_include_directories(ImagifyGUI SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/Source/Libraries/")
target_include_directories(ImagifyGUI SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/Source/Libraries/ImageProcessing")