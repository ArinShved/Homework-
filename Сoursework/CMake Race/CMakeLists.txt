# CMakeList.txt: проект CMake для CMake Race; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMake Race")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "CMake Race.cpp" "CMake Race.h" "functions.cpp" "functions.h" )
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Type_of_vehicle SHARED "air_vehicle.h" "air_vehicles.cpp" "all_terrain_boots.cpp" "all_terrain_boots.h" "broom.cpp" "broom.h" "camel.cpp" "camel.h" "camel_speedboad.cpp" "camel_speedboad.h" "carpet_plane.cpp" "carpet_plane.h" "centaur.cpp" "centaur.h" "eagle.cpp" "eagle.h" "ground_vehicle.cpp" "ground_vehicle.h" "vehicle.cpp" "vehicle.h" "air_vehicle.h" "air_vehicles.cpp" "all_terrain_boots.cpp" "all_terrain_boots.h" "broom.cpp" "broom.h" "camel.cpp" "camel.h" "camel_speedboad.cpp" "camel_speedboad.h" "carpet_plane.cpp" "carpet_plane.h" "centaur.cpp" "centaur.h" "eagle.cpp" "eagle.h" "ground_vehicle.cpp" "ground_vehicle.h")
target_link_libraries(CMakeTarget Type_of_vehicle)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
