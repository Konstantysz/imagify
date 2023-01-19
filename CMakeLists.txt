cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(Imagify LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up our output directories
set(BINARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LIBRARY_OUTPUT_DIRECTORY}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BINARY_OUTPUT_DIRECTORY}/$<CONFIGURATION>")

set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakePredefinedTargets")

# Enable solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Disable ZERO_CHECK
set(CMAKE_SUPPRESS_REGENERATION true)

set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Conan shit
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(
        DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.17.0/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake"
        EXPECTED_HASH SHA256=3bef79da16c2e031dc429e1dac87a08b9226418b300ce004cc125a82687baeef
        TLS_VERIFY ON)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(${CMAKE_BINARY_DIR}/conan.cmake)

# For multi configuration generators, like VS and XCode
if(NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Single configuration build!")
    set(LIST_OF_BUILD_TYPES ${CMAKE_BUILD_TYPE})
    else()
    message(STATUS "Multi-configuration build: '${CMAKE_CONFIGURATION_TYPES}'!")
    set(LIST_OF_BUILD_TYPES ${CMAKE_CONFIGURATION_TYPES})
endif()

foreach(TYPE ${LIST_OF_BUILD_TYPES})
    message(STATUS "Running Conan for build type '${TYPE}'")

    # Detects current build settings to pass into conan
    conan_cmake_autodetect(settings BUILD_TYPE ${TYPE})
    # conan_cmake_autodetect(settings)

    # PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR} is used to tell conan to process the external "conanfile.py" provided with the project Alternatively a
    # conanfile.txt could be used
    conan_cmake_install(
        PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}
        BUILD missing
        REMOTE cci
        SETTINGS ${settings})
endforeach()
# End of conan shit

add_subdirectory(source)
