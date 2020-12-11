cmake_minimum_required(VERSION 3.10)

# set the project name
project(SC_CMAKE VERSION 1.0)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# control where the static and shared libraries are built so that
# we don't need to tinker with thee path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "BUild using shared libraries" ON)
configure_file(Config.h.in Config.h)

# add the MathFunctions library
add_subdirectory(MathFunctions)

# add the executable
add_executable(SC_CMAKE main.cpp)
target_link_libraries(SC_CMAKE PUBLIC MathFunctions)
target_include_directories(SC_CMAKE PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS SC_CMAKE DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Config.h"
  DESTINATION include)

