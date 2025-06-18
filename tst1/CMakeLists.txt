cmake_minimum_required(VERSION 3.20.0)

set (ZEPHYR_EXTRA_MODULES "${CMAKE_SOURCE_DIR}/../modules/say_hello" )

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(tst1)

target_include_directories(app PRIVATE include)

#target_sources(app PRIVATE 
#                    src/main.c
#                    src/my_lib.c
#                    )

file(GLOB APP_SOURCES "src/*.c")  # Находит все .c файлы в src/
target_sources(app PRIVATE ${APP_SOURCES})
