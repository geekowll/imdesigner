cmake_minimum_required(VERSION 3.5)
project(stgui)

add_definitions(-DSTB_IMAGE_IMPLEMENTATION)
add_definitions(-DLOGGING)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include/ui
                    include/utility
                    ../imgui/include
                    ${OPENGL_INCLUDE_DIR}
                    ${GLEW_INCLUDE_DIRS}
                    ${GLFW_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES include/*.hpp
                          src/*.cpp )

#add_executable(${PROJECT_NAME} ${SOURCES})
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} 
    imgui
    stdc++fs
    pthread
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES})
