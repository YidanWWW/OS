cmake_minimum_required(VERSION 3.10)
project(MyOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files from the include/ directory
include_directories(include)

# Collect all source files from the src/ directory
file(GLOB SRC_FILES "src/*.cpp")

# Create the executable
add_executable(MyOS ${SRC_FILES})
