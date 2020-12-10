add_executable(MakeTable MakeTable.cpp)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )

set_source_files_properties(
  mysqrt.cpp PROPERTIES
  OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(MathFunctions
  mysqrt.cpp
  )

target_include_directories(MathFunctions
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)

