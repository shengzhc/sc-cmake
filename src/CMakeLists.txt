cmake_minimum_required(VERSION 3.10)


# set the project name
project(SC_CMAKE VERSION 1.0)

option(USE_MYMATH "Use totorial provided math implementation" ON)
configure_file(Config.h.in Config.h)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add libraries
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(SC_CMAKE main.cpp)

target_link_libraries(SC_CMAKE PUBLIC ${EXTRA_LIBS})

target_include_directories(SC_CMAKE PUBLIC 
  "${PROJECT_BINARY_DIR}" 
  ${EXTRA_INCLUDES}
)
