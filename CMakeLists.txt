cmake_minimum_required(VERSION 3.0.0)
project(Club_Event VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-Wall)
add_subdirectory(include)
add_subdirectory(src)


add_executable(Club_Event main.cpp)

target_link_libraries(Club_Event def impl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
