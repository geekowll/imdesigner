cmake_minimum_required(VERSION 3.5)
project(imgui)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLEW)

find_package(OpenGL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

find_package(GLEW REQUIRED)

include_directories(include)

file(GLOB SOURCES include/*.h src/*.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} 
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES})

