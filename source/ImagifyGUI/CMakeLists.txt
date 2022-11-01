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

# Set debugger working directory for compliance with gtest working directory
if (CMAKE_GENERATOR MATCHES "Visual Studio")
	set_target_properties(ImagifyGUI PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:ImagifyGUI>")
endif()

target_link_libraries(ImagifyGUI PUBLIC ${wxWidgets_LIBRARIES})

target_link_libraries(ImagifyGUI PUBLIC Core)
target_include_directories(ImagifyGUI SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/source/Libraries/")
target_include_directories(ImagifyGUI SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/source/Libraries/ImageProcessing")