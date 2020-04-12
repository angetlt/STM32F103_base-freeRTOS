/*Базовый проект для микроконтроллера STM32F103VE (high-density)*/
/**
 * Используется CMSIS v.5.6.0
 * 
 * Используется freeRTOS v.10.3.1
 * Для выбора типа используемой памяти в Makefile указать heap_x.c
 */

#include <stdio.h>
#include <stm32f10x.h>

#include "gpio_stm32f1.h"
#include "main.h"

/*freeRTOS includes*/
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

/*MAIN*/
int main(int argc, char *argv[])
{
	/*IO_Init();*/

	while (1)
	{
	}
}
