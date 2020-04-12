# STM32F103_base
Base VSC project for STM32F103 (CMSIS, freeRTOS, windows-build-tools, GCC compiler, J-Link)

Базовый проект для микроконтроллера STM32F103 в Visual Studio Code.
Прошивка содержит:
* CMSIS v.5.6.0
* freeRTOS v.10.3.1 (для выбора типа используемой памяти в Makefile указать heap_x.c)

Используемые инструменты:
* Visual Studio Code c расширениями:
    * C/C++;
    * C++ Intellisense;
    * Cortex-Debug;
* Сборщик windows-build-tools: https://github.com/gnu-mcu-eclipse/windows-build-tools/releases;
* Компилятор GCC arm-none-eabi-gcc: https://github.com/ilg-archived/arm-none-eabi-gcc/releases/;
* Прошивка и отладка J-Link debugger

Имя файла прошивки соответствует имени папки проекта.



