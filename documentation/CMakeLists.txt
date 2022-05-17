# Zeta - documentation/CMakeLists.txt
#  ______ ____________  ___
# |__   /|  ___|__  __|/   \
#   /  /_|  __|  |  | /  *  \
#  /_____|_____| |__|/__/ \__\
# Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
# # Released under the terms of the GNU Lesser General Public License v3.

find_package(Doxygen REQUIRED)
find_package(Sphinx  REQUIRED)
find_package(Breathe REQUIRED)

set(DOXYGEN_INPUT_DIR  "${PROJECT_SOURCE_DIR}/API"		)
set(DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/doxygen"	)
set(_DOXYFILE_IN       "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
set(_DOXYFILE	       "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"	)
set(_SPHINX_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/sphinx"	)

get_target_property(DOXYGEN_INCLUDE_PATH Zeta INTERFACE_INCLUDE_DIRECTORIES)

configure_file(${_DOXYFILE_IN} ${_DOXYFILE} @ONLY)

file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})
file(MAKE_DIRECTORY ${_SPHINX_OUTPUT_DIR})

file(GLOB_RECURSE PUBLIC_HEADERS ${DOXYGEN_INPUT_DIR}/*.h)

set(_DOXYGEN_XML_OUTPUT "${DOXYGEN_OUTPUT_DIR}/xml")

add_custom_command(
	OUTPUT  ${_DOXYGEN_XML_OUTPUT}
	DEPENDS ${_PUBLIC_HEADERS}
	COMMAND ${DOXYGEN_EXECUTABLE} ${_DOXYFILE}
	MAIN_DEPENDENCY ${_DOXYFILE} ${_DOXYFILE_IN}
	COMMENT "Extracting API reference")

add_custom_target(Doxygen-XML ALL DEPENDS ${_DOXYGEN_XML_OUTPUT})

if(WITH_HTML_DOCUMENTATION)
	set(_SPHINX_HTML_OUTPUT "${_SPHINX_OUTPUT_DIR}/html")

	add_custom_command(
		OUTPUT  ${_SPHINX_HTML_OUTPUT}
		COMMAND ${SPHINX_BUILD_EXECUTABLE}
			-b html
			"-Dbreathe_projects.${PROJECT_NAME}=${_DOXYGEN_XML_OUTPUT}"
			${CMAKE_CURRENT_SOURCE_DIR}
			${_SPHINX_HTML_OUTPUT}
		MAIN_DEPENDENCY ${_DOXYGEN_XML_OUTPUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating documentation in HTML format")

	add_custom_target(Sphinx-HTML ALL DEPENDS ${_SPHINX_HTML_OUTPUT})
	add_dependencies(Sphinx-HTML Doxygen-XML)

	install(DIRECTORY "${_SPHINX_OUTPUT_DIR}/html/"
		DESTINATION "${CMAKE_INSTALL_DOCDIR}/documentation")
endif()

if(WITH_PDF_DOCUMENTATION)
	find_package(LATEX REQUIRED COMPONENTS PDFLATEX)

	set(_SPHINX_LATEX_OUTPUT "${_SPHINX_OUTPUT_DIR}/latex")

	add_custom_command(
		OUTPUT  ${_SPHINX_LATEX_OUTPUT}
		COMMAND ${SPHINX_BUILD_EXECUTABLE}
			-b latex
			"-Dbreathe_projects.${PROJECT_NAME}=${_DOXYGEN_XML_OUTPUT}"
			${CMAKE_CURRENT_SOURCE_DIR}
			${_SPHINX_LATEX_OUTPUT}
		MAIN_DEPENDENCY ${_DOXYGEN_XML_OUTPUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating documentation in LaTeX format")

	add_custom_target(Sphinx-LaTeX ALL DEPENDS ${_SPHINX_LATEX_OUTPUT})
	add_dependencies(Sphinx-LaTeX Doxygen-XML)

	set(_LATEX_PDF_OUTPUT "${_SPHINX_LATEX_OUTPUT}/zeta.pdf")

	add_custom_command(
		OUTPUT  ${_LATEX_PDF_OUTPUT}
		COMMAND make
		MAIN_DEPENDENCY ${_SPHINX_LATEX_OUTPUT}
		WORKING_DIRECTORY ${_SPHINX_LATEX_OUTPUT}
		COMMENT "Converting documentation to PDF format")

	add_custom_target(LaTeX-PDF ALL DEPENDS ${_LATEX_PDF_OUTPUT})
	add_dependencies(LaTeX-PDF Sphinx-LaTeX)

	install(FILES ${_LATEX_PDF_OUTPUT}
		DESTINATION ${CMAKE_INSTALL_DOCDIR}
		RENAME "${PROJECT_NAME} v${PROJECT_VERSION}.pdf")
endif()

# documentation/CMakeLists.txt EOF
