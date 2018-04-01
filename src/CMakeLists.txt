cmake_minimum_required(VERSION 3.9.2)
project(HandCodedTPCH)

include(CTest)

# The version number.
set (HandCodedTPCH_VERSION_MAJOR 0)
set (HandCodedTPCH_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings to the source code.
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

# add the binary tree to the search path for include files so that we could
# find "config.h".
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/util")

# add all the directories needed to build here.
add_subdirectory(thirdpart-libs/gtest/googletest)
add_subdirectory(util)
add_subdirectory(test)

# add the executable
add_executable(HandCodedTPCH main.cc)

install(TARGETS HandCodedTPCH DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)
