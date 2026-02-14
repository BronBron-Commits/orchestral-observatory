cmake_minimum_required(VERSION 3.10)
project(OrchestratorObservatory VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

# Source files
set(SOURCES
    src/main.cpp
    src/Renderer.cpp
    src/Grid.cpp
    src/Octagon.cpp
    src/Node.cpp
    src/Line.cpp
    src/ShaderProgram.cpp
)

# Executable
add_executable(orchestral_observatory ${SOURCES})

# Link libraries
target_link_libraries(orchestral_observatory
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    GL
    m
)

# Copy shaders to build directory
file(COPY ${CMAKE_SOURCE_DIR}/shaders DESTINATION ${CMAKE_BINARY_DIR})
