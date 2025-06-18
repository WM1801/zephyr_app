Проекты для zephyr


cmake_demo - минимальный проект для zephyr, собирал в docker https://github.com/zephyrproject-rtos/docker-image
esp32s3: https://docs.zephyrproject.org/latest/boards/espressif/esp32s3_devkitc/doc/index.html
https://www.youtube.com/watch?v=mTJ_vKlMS_4&list=PLEBQazB0HUyTmK2zdwhaf8bLwuEaDH-52&index=3 


west update  
west blobs fetch hal_espressif

Структура 
```
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
```
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

***прошивка с помощью west***
```
west flahs
```

***прошивка с помощью esptool ***
```
python -m esptool --port "COM7" --chip auto --baud 921600 --before default_reset --after hard_reset write_flash -u --flah_size detect 0x0 .\workspace\build\zephyr\zephyr.bin


esptool.py --chip esp32s3 -p /dev/ttyACM0 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 80m --flash_size 2MB 0x0 ./build/mcuboot/zephyr/zephyr.bin 0x10000 ./build/hello_world/zephyr/zephyr.bin
```


***сборка через cmake***
```

cmake -G "Ninja" -DBOARD=jc4827w543/esp32s3/procpu -DDTC_OVERLAY_FILE=board/jc4827w543.overlay -B build -S .

cmake --build build 

west flash 
```
***сборка через west*** 
```
west build -b jc4827w543/esp32s3/procpu ./app/cmake_demo/ --pristine

west flash 
```
***cборка с добавлением dts overlay***
```
west build -b jc4827w543/esp32s3/procpu ./app/tst1/ --pristine -- -DDTC_OVERLAY_FILE=/workdir/app/tst1/board/jc4827w543.overlay 

```
***запуск Kconfig***
```
west build -b jc4827w543/esp32s3/procpu ./app/tst1/ -t menuconfig --pristine -- -DDTC_OVERLAY_FILE=/workdir/app/tst1/board/jc4827w543.overlay 
```
***замещение конфига (prj.conf) для платы, что бы не применять настройки в prj.conf***
```
west build -b jc4827w543/esp32s3/procpu ./app/tst1/ --pristine -- -DDTC_OVERLAY_FILE=/workdir/app/tst1/board/jc4827w543.overlay -DCONF_FILE=/workdir/app/tst1/board/jc4827w543.conf
```
***включение дополнительного конфига помимо prj.conf***
```
west build -b jc4827w543/esp32s3/procpu ./app/tst1/ --pristine -- -DDTC_OVERLAY_FILE=/workdir/app/tst1/board/jc4827w543.overlay -DEXTRA_CONF_FILE=/workdir/app/tst1/board/jc4827w543.conf
```