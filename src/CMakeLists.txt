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
endif()

# add the executable
add_executable(SC_CMAKE main.cpp)

target_link_libraries(SC_CMAKE PUBLIC ${EXTRA_LIBS})

target_include_directories(SC_CMAKE PUBLIC 
  "${PROJECT_BINARY_DIR}" 
)

install(TARGETS SC_CMAKE DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Config.h"
  DESTINATION include
)

enable_testing()
# does the application run
add_test(NAME Runs COMMAND SC_CMAKE 100)
# does the usage message work?
add_test(NAME Usage COMMAND SC_CMAKE)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(SC_CMAKE 4 "4 is 2")
do_test(SC_CMAKE 9 "9 is 3")
do_test(SC_CMAKE 5 "5 is 2.236")
do_test(SC_CMAKE 7 "7 is 2.645")
do_test(SC_CMAKE 25 "25 is 5")
do_test(SC_CMAKE -25 "-25 is [-nan|nan|0]")
do_test(SC_CMAKE 0.0001 "0.0001 is 0.01")

include(InstallRequiredSystemLibraries)
set(CPAKC_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${SC_CMAKE_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${SC_CMAKE_VERSION_MINOR}")
include(CPack)
