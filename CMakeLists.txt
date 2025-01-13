cmake_minimum_required (VERSION 3.8)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML")

find_package(SFML 2.6.1 COMPONENTS graphics window system audio REQUIRED)

project ("XYZEngine")
add_subdirectory ("XYZEngine")