cmake_minimum_required(VERSION 3.10)

# set the project name
project(SC_CMAKE VERSION 1.0)
configure_file(Config.h.in Config.h)

# add the executable
add_executable(SC_CMAKE main.cpp)
target_include_directories(SC_CMAKE PUBLIC "${PROJECT_BINARY_DIR}")
