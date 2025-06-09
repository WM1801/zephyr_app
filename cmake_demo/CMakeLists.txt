#cmake_minimum_required(VERSION 3.20.0)

#project(
#    cmake_demo
#    VERSION 1.0.0
#    DESCRIPTION "CMake demo"
#    LANGUAGES C
#    )
#add_library(
#    my_lib
#    STATIC
#    src/my_lib.c
#)

#target_include_directories(
#    my_lib
#    PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/include/
#)

#add_executable(
#    ${PROJECT_NAME}
#    src/main.c
#)

#target_link_libraries(
#    ${PROJECT_NAME}
#    PRIVATE
#    my_lib
#)

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(cmake_demo)

target_include_directories(app PRIVATE include)

#target_sources(app PRIVATE 
#                    src/main.c
#                    src/my_lib.c
#                    )

file(GLOB APP_SOURCES "src/*.c")  # Находит все .c файлы в src/
target_sources(app PRIVATE ${APP_SOURCES})