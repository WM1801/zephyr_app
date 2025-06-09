Проекты для zephyr


cmake_demo - минимальный проект для zephyr, собирал в docker https://github.com/zephyrproject-rtos/docker-image
esp32s3: https://docs.zephyrproject.org/latest/boards/espressif/esp32s3_devkitc/doc/index.html
https://www.youtube.com/watch?v=mTJ_vKlMS_4&list=PLEBQazB0HUyTmK2zdwhaf8bLwuEaDH-52&index=3 


west update  
west blobs fetch hal_espressif

Структура 
$tree
.
├── board
│   └── jc4827w543.overlay
├── CMakeLists.txt
├── include
│   └── my_lib.h
├── prj.conf
└── src
    ├── main.c
    └── my_lib.c

3 directories, 6 files

CMakeLists.txt 
```
cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(cmake_demo)
target_include_directories(app PRIVATE include)
file(GLOB APP_SOURCES "src/*.c") # Находит все .c файлы в src/
target_sources(app PRIVATE ${APP_SOURCES})
```

сборка через cmake
```

cmake -G "Ninja" -DBOARD=jc4827w543/esp32s3/procpu -DDTC_OVERLAY_FILE=board/jc4827w543.overlay -B build -S .

cmake --build build 

west flash 
```
сборка через west 
```
west build -b jc4827w543/esp32s3/procpu ./app/cmake_demo/ --pristine

west flash 

```
