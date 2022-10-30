cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(Imagify LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakePredefinedTargets")

# Enable solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Disable ZERO_CHECK
set(CMAKE_SUPPRESS_REGENERATION true)

set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)

add_subdirectory(Source)
