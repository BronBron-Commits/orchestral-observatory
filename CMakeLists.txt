cmake_minimum_required(VERSION 3.16)
project(orchestral-observatory)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} "C:/Libraries/SDL2/include" "C:/Libraries/GLEW/include")

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

include_directories(include)

add_executable(orchestral-observatory ${SOURCES})

target_link_libraries(orchestral-observatory ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
