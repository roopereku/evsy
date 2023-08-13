cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(.. build)

project(simpleexample)
add_executable(simpleexample simple.cc)
target_link_libraries(simpleexample evsy)

project(multiplehandlers)
add_executable(multiplehandlers multiplehandlers.cc)
target_link_libraries(multiplehandlers evsy)
