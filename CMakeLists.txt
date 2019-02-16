cmake_minimum_required(VERSION 3.5)
project(imdesigner)

add_subdirectory(imgui)
add_subdirectory(stgui)
add_subdirectory(test)

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
