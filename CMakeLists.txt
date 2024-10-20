cmake_minimum_required(VERSION 3.0.0)
project(3DEngine VERSION 0.1.0)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all source files in the src directory and its subdirectories
file(GLOB_RECURSE SOURCES src/*.c src/*.cpp src/*.h src/*.hpp)

# Include the current source directory in the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Include the GLM headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third-party)

# Set the OpenGL_GL_PREFERENCE variable to "GLVND"
set(OpenGL_GL_PREFERENCE "GLVND")

# Add the executable target
add_executable(3DEngine ${SOURCES})

# Find and link SDL2 and SDL2_image
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

link_directories(/usr/lib/x86_64-linux-gnu)
target_link_libraries(3DEngine SDL2_image)

# Link against the necessary libraries
target_link_libraries(3DEngine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Link against the OpenGL library
find_package(OpenGL REQUIRED)
target_link_libraries(3DEngine OpenGL::GL)