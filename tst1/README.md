Проект основан на https://www.youtube.com/watch?v=dXx1Wc15NZE&list=PLEBQazB0HUyTmK2zdwhaf8bLwuEaDH-52&index=4 работа с Kconfig

В проекте производится:
 - настройка overlay для мигания светодиодом;
 - создание своей библиотеки;
 - добавление ее в меню Kconfig
 - создание дополнительного файла config
 - настройка поддержки float
 - создание генератора случайных чисел  


***сборка:***
```
west build -b jc4827w543/esp32s3/procpu ./app/tst1/ --pristine -- -DDTC_OVERLAY_FILE=/workdir/app/tst1/board/jc4827w543.overlay -DEXTRA_CONF_FILE=/workdir/app/tst1/board/jc4827w543.conf
```
***menuconfig***
```
west build -b jc4827w543/esp32s3/procpu -t menuconfig ./app/tst1/ --pristine -- -DDTC_OVERLAY_FILE=/workdir/app/tst1/board/jc4827w543.overlay -DEXTRA_CONF_FILE=/workdir/app/tst1/board/jc4827w543.conf
```
***прошивка***
```
west flash 
```
