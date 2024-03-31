
cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Class_hierarchy_cmake")

add_executable (Class_hierarchy_cmake "equilateral_triangle.cpp" "equilateral_triangle.h" "figure.cpp" "figure.h" "isosceles_triangle.cpp" "isosceles_triangle.h" "main.cpp" "parallelogram.cpp" "parallelogram.h" "quadrangle.cpp" "quadrangle.h" "rectangle.cpp" "rectangle.h" "rhombus.cpp" "rhombus.h" "right_triangle.cpp" "right_triangle.h" "square.cpp" "square.h" "triangle.cpp" "triangle.h")



