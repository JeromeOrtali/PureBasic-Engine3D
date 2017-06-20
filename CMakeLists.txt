# Set project name
project (Engine3D)
# Set minimum version
cmake_minimum_required (VERSION 2.8.6)


ADD_DEFINITIONS(-D_SECURE_SCL=0)
ADD_DEFINITIONS(-D_HAS_ITERATOR_DEBUGGING=0)


if (COMMAND cmake_policy)
    cmake_policy (SET CMP0003 NEW)
    if (CMAKE_VERSION VERSION_GREATER 2.8.12 OR CMAKE_VERSION VERSION_EQUAL 2.8.12)
        # INTERFACE_LINK_LIBRARIES defines the link interface
        cmake_policy (SET CMP0022 NEW)
    endif ()
    if (CMAKE_VERSION VERSION_GREATER 3.0.0 OR CMAKE_VERSION VERSION_EQUAL 3.0.0)
        # Disallow use of the LOCATION target property - therefore we set to OLD as we still need it
        cmake_policy (SET CMP0026 OLD)
        # MACOSX_RPATH is enabled by default
        cmake_policy (SET CMP0042 NEW)
    endif ()
endif ()




# Set CMake modules search path
set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)
# Include Urho3D Cmake common module
include (Urho3D-CMake-common)
# Find Urho3D library
find_package (Urho3D REQUIRED)
include_directories (${URHO3D_INCLUDE_DIRS})
include_directories (include)

# Define target name
set (TARGET_NAME Engine3D)

# Define source files
file (GLOB CPP_FILES src/*.cpp)
file (GLOB H_FILES include/*.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binary/bin)
setup_library(SHARED)