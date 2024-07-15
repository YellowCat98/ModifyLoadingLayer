cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(ModifyLoadingLayer VERSION 1.0.0)

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/Editor/CustomLoadingLayer.hpp
    src/Editor/CustomLoadingLayer.cpp
    src/Loader/LoadignLayer.cpp
    src/Editor/DragNode.hpp
    src/Editor/DragNode.cpp
    src/MLLManager.cpp
    src/MLLManager.hpp
    src/Editor/LoadingEditorUI.cpp
    src/Editor/LoadingEditorUI.hpp
    src/Editor/Rotation.cpp
    src/Editor/Rotation.hpp
    src/Editor/Scale.cpp
    src/Editor/Scale.hpp
    src/Editor/InputPopup.cpp
    src/Editor/InputPopup.hpp
    src/Editor/RGBA.hpp
    src/Editor/RGBA.cpp
)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Set up dependencies, resources, link Geode
setup_geode_mod(${PROJECT_NAME})
