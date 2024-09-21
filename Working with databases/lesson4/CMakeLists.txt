cmake_minimum_required(VERSION 3.20)

project(PostSQlinC)

add_subdirectory(libpqxx-7.9.2)

add_executable(PostSQLinC main.cpp)

target_compile_features(PostSQLinC PRIVATE cxx_std_17)

target_link_libraries(PostSQLinC PRIVATE pqxx)
