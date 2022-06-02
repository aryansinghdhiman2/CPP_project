cmake_minimum_required(VERSION 3.0.0)
project(Club_Event VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-Wall)
add_compile_options(-std=c++20)
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(other)

add_executable(Club_Event main.cpp)

target_link_libraries(Club_Event def impl)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/other/event.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/other/event.txt
    ${CMAKE_CURRENT_SOURCE_DIR} COPYONLY)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
