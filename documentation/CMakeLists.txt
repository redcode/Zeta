# Zeta - documentation/CMakeLists.txt
#  ______ ____________  ___
# |__   /|  ___|__  __|/   \
#   /  /_|  __|  |  | /  *  \
#  /_____|_____| |__|/__/ \__\
# Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
# # Released under the terms of the GNU Lesser General Public License v3.

find_package(Sphinx REQUIRED)

if(${PROJECT_NAME}_WITH_HTML_DOCUMENTATION)
	set(_html_documentation_output "${CMAKE_CURRENT_BINARY_DIR}/HTML")

	if(${PROJECT_NAME}_SPHINX_HTML_THEME STREQUAL "")
		set(_html_theme_option "")
	else()
		set(_html_theme_option "-Dhtml_theme=${${PROJECT_NAME}_SPHINX_HTML_THEME}")
	endif()

	add_custom_command(
		OUTPUT  ${_html_documentation_output}
		COMMAND ${SPHINX_BUILD_EXECUTABLE}
			-b html
			${_html_theme_option}
			${CMAKE_CURRENT_SOURCE_DIR}
			${_html_documentation_output}
		MAIN_DEPENDENCY ${_api_xml_output}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating documentation in HTML format")

	add_custom_target(
		${PROJECT_NAME}-Documentation-HTML ALL
		DEPENDS ${_html_documentation_output})

	install(DIRECTORY "${_html_documentation_output}/"
		DESTINATION "${CMAKE_INSTALL_DOCDIR}/documentation"
		COMPONENT "${PROJECT_NAME}_Documentation")
endif()

if(${PROJECT_NAME}_WITH_PDF_DOCUMENTATION)
	find_package(LATEX REQUIRED COMPONENTS PDFLATEX)

	set(_latex_documentation_output "${CMAKE_CURRENT_BINARY_DIR}/LaTeX")

	add_custom_command(
		OUTPUT  ${_latex_documentation_output}
		COMMAND ${SPHINX_BUILD_EXECUTABLE}
			-b latex
			${CMAKE_CURRENT_SOURCE_DIR}
			${_latex_documentation_output}
		MAIN_DEPENDENCY ${_api_xml_output}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating documentation in LaTeX format")

	add_custom_target(
		${PROJECT_NAME}-Documentation-LaTeX ALL
		DEPENDS ${_latex_documentation_output})

	string(TOLOWER ${PROJECT_NAME} _pdf_documentation_output)
	set(_pdf_documentation_output "${_latex_documentation_output}/${_pdf_documentation_output}.pdf")

	add_custom_command(
		OUTPUT  ${_pdf_documentation_output}
		COMMAND make
		MAIN_DEPENDENCY ${_latex_documentation_output}
		WORKING_DIRECTORY ${_latex_documentation_output}
		COMMENT "Converting documentation to PDF format")

	add_custom_target(
		${PROJECT_NAME}-Documentation-PDF ALL
		DEPENDS ${_pdf_documentation_output})

	add_dependencies(${PROJECT_NAME}-Documentation-PDF ${PROJECT_NAME}-Documentation-LaTeX)

	install(FILES ${_pdf_documentation_output}
		DESTINATION ${CMAKE_INSTALL_DOCDIR}
		RENAME "${PROJECT_NAME} v${PROJECT_VERSION}.pdf"
		COMPONENT "${PROJECT_NAME}_Documentation")
endif()

# documentation/CMakeLists.txt EOF
