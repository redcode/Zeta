# Zeta - CMakeLists.txt
#  ______ ____________  ___
# |__   /|  ___|__  __|/   \
#   /  /_|  __|  |  | /  *  \
#  /_____|_____| |__|/__/ \__\
# Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
# # Released under the terms of the GNU Lesser General Public License v3.

cmake_minimum_required(VERSION 3.1.3)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/API/Z/version.h" _)
string(REGEX MATCH ".*Z_LIBRARY_VERSION_STRING \"([^\n]*)\".*" _ ${_})
project(Zeta VERSION ${CMAKE_MATCH_1} LANGUAGES C)
unset(_)
message("${PROJECT_NAME} v${PROJECT_VERSION}")

include(GNUInstallDirs)

set(${PROJECT_NAME}_INSTALL_CMAKEDIR
"${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake" CACHE STRING
"Specify the directory in which to install the CMake config-file package.")

set(${PROJECT_NAME}_INSTALL_PKGCONFIGDIR
"${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig" CACHE STRING
"Specify the directory in which to install the pkg-config file.")

set(${PROJECT_NAME}_SPHINX_HTML_THEME
"" CACHE STRING
"Specify the Sphinx theme for the documentation in HTML format.")

option(${PROJECT_NAME}_WITH_CMAKE_SUPPORT
"Generate and install the CMake config-file package."
NO)

option(${PROJECT_NAME}_WITH_HTML_DOCUMENTATION
"Build and install the documentation in HTML format."
NO)

option(${PROJECT_NAME}_WITH_PDF_DOCUMENTATION
"Build and install the documentation in PDF format."
NO)

option(${PROJECT_NAME}_WITH_PKGCONFIG_SUPPORT
"Generate and install the pkg-config file."
NO)

option(${PROJECT_NAME}_WITH_STANDARD_DOCUMENTS
"Install the standard text documents distributed with the package: \
AUTHORS, COPYING, COPYING.LESSER, HISTORY, README and THANKS."
NO)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
	${PROJECT_NAME} INTERFACE
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/API>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

install(TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}_Targets")

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/API/Z"
	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
	COMPONENT "${PROJECT_NAME}_Development")

if(${PROJECT_NAME}_WITH_CMAKE_SUPPORT OR ${PROJECT_NAME}_WITH_PKGCONFIG_SUPPORT)
	include(CMakePackageConfigHelpers)

	if(${PROJECT_NAME}_WITH_CMAKE_SUPPORT)
		install(EXPORT "${PROJECT_NAME}_Targets"
			DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR}
			FILE ${PROJECT_NAME}Targets.cmake
			COMPONENT ${PROJECT_NAME}_Development)

		write_basic_package_version_file(
			"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
			VERSION ${PROJECT_VERSION}
			COMPATIBILITY SameMajorVersion)

		configure_package_config_file(
			"${CMAKE_CURRENT_SOURCE_DIR}/support/${PROJECT_NAME}Config.cmake.in"
			"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
			INSTALL_DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})

		install(FILES
			"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
			"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
			DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR}
			COMPONENT ${PROJECT_NAME}_Development)
	endif()

	if(${PROJECT_NAME}_WITH_PKGCONFIG_SUPPORT)
		configure_file(
			"${CMAKE_CURRENT_SOURCE_DIR}/support/${PROJECT_NAME}.pc.in"
			"${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc"
			@ONLY)

		install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
			DESTINATION ${${PROJECT_NAME}_INSTALL_PKGCONFIGDIR}
			COMPONENT ${PROJECT_NAME}_Development)
	endif()
endif()

if(${PROJECT_NAME}_WITH_STANDARD_DOCUMENTS)
	install(FILES	"${CMAKE_CURRENT_SOURCE_DIR}/AUTHORS"
			"${CMAKE_CURRENT_SOURCE_DIR}/COPYING"
			"${CMAKE_CURRENT_SOURCE_DIR}/COPYING.LESSER"
			"${CMAKE_CURRENT_SOURCE_DIR}/HISTORY"
			"${CMAKE_CURRENT_SOURCE_DIR}/README"
			"${CMAKE_CURRENT_SOURCE_DIR}/THANKS"
		DESTINATION ${CMAKE_INSTALL_DOCDIR}
		COMPONENT "${PROJECT_NAME}_Development")
endif()

if(${PROJECT_NAME}_WITH_HTML_DOCUMENTATION OR ${PROJECT_NAME}_WITH_PDF_DOCUMENTATION)
	add_subdirectory(documentation)
endif()

# CMakeLists.txt EOF
