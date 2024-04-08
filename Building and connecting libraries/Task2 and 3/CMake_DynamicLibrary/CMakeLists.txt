cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMake_DynamicLibrary")

add_library(Dunamiclibrary SHARED leaver.cpp leaver.h )

add_executable (CMake_DynamicLibrary "CMake_DynamicLibrary.cpp" "CMake_DynamicLibrary.h")
target_link_libraries(CMake_DynamicLibrary Dunamiclibrary)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMake_DynamicLibrary PROPERTY CXX_STANDARD 20)
endif()