file(GLOB ImagifySource "*.cpp" "*.h" "*.qrc" "*.ui")

# Look for Qt environmental variable
if(DEFINED ENV{Qt5_Dir})
    set(QTDIR $ENV{Qt5_Dir})
elseif(DEFINED ENV{Qt5_DIR})
    set(QTDIR $ENV{Qt5_DIR})
elseif(DEFINED ENV{QTDIR})
    set(QTDIR $ENV{QTDIR})
endif()

# Find Qt packages
if(DEFINED QTDIR)
    message("Using Qt env path: ${QTDIR}.")
    find_package(Qt5 
        COMPONENTS Core Gui Widgets OpenGL
        REQUIRED
        CONFIG
        PATHS
        ${QTDIR}
        NO_DEFAULT_PATH)
else()
    message("Using Qt default path.")
    find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)
endif()

# Enable auto-generation of Qt files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Imagify ${ImagifySource})

# Set Qt libraries variable
set(QtLibraries Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL)
target_link_libraries(Imagify PUBLIC ${QtLibraries})

set_target_properties(Imagify PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

# Copy Qt libs
foreach(qt_lib ${QtLibraries})
    add_custom_command(
        TARGET Imagify
        POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${qt_lib}> $<TARGET_FILE_DIR:Imagify>)
endforeach()

# Copy plugins
if(WIN32)
    set(QtPlugins "platforms" "styles" "imageformats")
    foreach(QtPlugin ${QtPlugins})
        add_custom_command(
            TARGET Imagify POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${QTDIR}/plugins/${QtPlugin}"
            "$<TARGET_FILE_DIR:Imagify>/${QtPlugin}")
    endforeach()
endif()

# Target libraries
target_link_libraries(Imagify PUBLIC Core)
target_include_directories(Imagify SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/source/Libraries/")
target_include_directories(Imagify SYSTEM PUBLIC "${PROJECT_SOURCE_DIR}/source/Libraries/Core")