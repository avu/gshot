# Set the name and the supported language of the project
PROJECT(hello-world C)
# Set the minimum version of cmake required to build this project
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
#PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-2.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
# INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
#INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
# LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
#LINK_DIRECTORIES(${GTK2_LIBRARY_DIRS})

# Add other flags to the compiler
# ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})
#ADD_DEFINITIONS(${GTK2_CFLAGS_OTHER})

find_package(GTK2 REQUIRED)
include_directories(${GTK2_INCLUDE_DIRS})

#pkg_check_modules(CAIRO REQUIRED Cairo )
#include_directories(${Cairo_INCLUDE_DIRS})

# Add an executable compiled from hello.c
ADD_EXECUTABLE(hello main.c)

# Link the target to the GTK+ libraries
# TARGET_LINK_LIBRARIES(hello ${GTK3_LIBRARIES})
TARGET_LINK_LIBRARIES(hello ${GTK2_LIBRARIES})
#target_link_libraries(hello ${Cairo_LIBRARIES})
