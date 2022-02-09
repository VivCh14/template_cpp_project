cmake_minimum_required(VERSION 3.0)
# Name of the project
project(myprojectdocs)
# find doxygen
find_package(Doxygen REQUIRED)

if (NOT CMAKE_BUILD_DOC)
    message(STATUS "Use -CMAKE_BUILD_DOC=FALSE for disabling docs")
    set(CMAKE_BUILD_DOC "TRUE")
endif()

# set the input and output documentation paths
set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR})
message("DOXYGEN_INPUT_DIR: " ${DOXYGEN_INPUT_DIR})
set(DOXYGEN_OUTPUT_DIR ${DOXYGEN_INPUT_DIR})
message("DOXYGEN_OUTPUT_DIR: " ${DOXYGEN_OUTPUT_DIR})

# configure the source Doxyfile by copying it and replacing all @variables@
set(DOXYGEN_CONFIGURED_INPUT ${DOXYGEN_OUTPUT_DIR}/doxyfile)
message("DOXYGEN_CONFIGURED_INPUT: " ${DOXYGEN_CONFIGURED_INPUT})
configure_file(${DOXYGEN_INPUT_DIR}/doxyfile.in ${DOXYGEN_CONFIGURED_INPUT} @ONLY)
configure_file(${DOXYGEN_INPUT_DIR}/header.html.in ${DOXYGEN_OUTPUT_DIR}/header.html @ONLY)

# copy the files needed by the documentation
configure_file(${DOXYGEN_INPUT_DIR}/custom.css ${DOXYGEN_OUTPUT_DIR}/html/custom.css COPYONLY)

# target setup
add_custom_target(doc ALL
                  COMMAND ${CMAKE_COMMAND} -E echo_append "Building Documentation..."
                  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIGURED_INPUT}
                  COMMAND ${CMAKE_COMMAND} -E echo "Done."
                  WORKING_DIRECTORY ${DOXYGEN_INPUT_DIR})

set(CMAKE_INSTALL_DOCDIR ${DOXYGEN_INPUT_DIR})
# setup install rules
install(FILES ${DOXYGEN_OUTPUT_DIR}/sample.tag
        DESTINATION ${CMAKE_INSTALL_DOCDIR}
        COMPONENT doc)
install(DIRECTORY ${DOXYGEN_OUTPUT_DIR}/html
        DESTINATION ${CMAKE_INSTALL_DOCDIR}
        COMPONENT doc)
