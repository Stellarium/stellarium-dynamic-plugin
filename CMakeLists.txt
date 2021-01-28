# Copyright (C) 2007 Fabien Chereau
# Copyright (C) 2015 Kirill Snezhko
# Copyright (C) 2018 Alexander Wolf
#
# Based on the HelloStelModule

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Set name of project (name of the plugin by the fact)
PROJECT(DynamicPluginTemplate)

# Set version of the plugin
SET(DYNAMICPLUGINTEMPLATE_VERSION "0.2.0")

# define requirements for C/C++ standards
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_C_STANDARD 11)

# Set variables for using inside of plugin
ADD_DEFINITIONS(-DDYNAMICPLUGINTEMPLATE_VERSION="${DYNAMICPLUGINTEMPLATE_VERSION}")
ADD_DEFINITIONS(-DDYNAMICPLUGINTEMPLATE_LICENSE="GPLv2+")

# Requirements
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)

# Stellarium source code directory
SET(STELLARIUM_SOURCE_DIR $ENV{STELROOT})

INCLUDE_DIRECTORIES(
     ${CMAKE_BINARY_DIR}
     ${CMAKE_SOURCE_DIR}/src
     ${CMAKE_SOURCE_DIR}/src/gui
     ${STELLARIUM_SOURCE_DIR}/src
     ${STELLARIUM_SOURCE_DIR}/src/core
     ${STELLARIUM_SOURCE_DIR}/src/core/modules
     ${STELLARIUM_SOURCE_DIR}/src/core/planetsephems
     ${STELLARIUM_SOURCE_DIR}/src/external
     ${STELLARIUM_SOURCE_DIR}/src/external/qtcompress
     ${STELLARIUM_SOURCE_DIR}/src/external/qcustomplot
     ${STELLARIUM_SOURCE_DIR}/src/external/qxlsx
     ${STELLARIUM_SOURCE_DIR}/src/external/glues_stel/source/
     ${STELLARIUM_SOURCE_DIR}/src/external/glues_stel/source/libtess
     ${STELLARIUM_SOURCE_DIR}/src/gui
     ${STELLARIUM_SOURCE_DIR}/src/scripting
     ${INTL_INCLUDE_DIR}
     ${CMAKE_BINARY_DIR}/src
     ${ZLIB_INCLUDE_DIR}
)

ADD_SUBDIRECTORY( src )

SET(CMAKE_INSTALL_PREFIX $ENV{HOME}/.stellarium)
INSTALL(FILES "${CMAKE_BINARY_DIR}/src/lib${PROJECT_NAME}.so" DESTINATION "modules/${PROJECT_NAME}")
