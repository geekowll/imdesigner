cmake_minimum_required (VERSION 3.5)
project(tst)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/stgui/include/ui
    ${CMAKE_SOURCE_DIR}/stgui/include/utility
    ${CMAKE_SOURCE_DIR}/imgui/include
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} 
    imgui
    stgui
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES})

