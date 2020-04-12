#include <stm32f10x.h>

#define IN (0x00)
#define OUT_10MHz (0x01)
#define OUT_2MHz (0x02)
#define OUT_50MHz (0x03)

#define OUT_PP (0x00)
#define OUT_OD (0x04)
#define OUT_APP (0x08)
#define OUT_AOD (0x0C)

#define IN_ADC (0x00)
#define IN_HIZ (0x04)
#define IN_PULL (0x08)

typedef enum
{
	OFF = 0,
	ON = 1,
	LOW = 0,
	HIGH = 1
} tIOState;

typedef struct
{
	GPIO_TypeDef *GPIOx; // Имя порта
	uint16_t GPIO_Pin;	 // Номер порта
	uint8_t MODE;		 // Режим
	uint8_t DefState;	 // Стартовое значение
} tGPIO_Line;

typedef enum
{
	o_D2 = 0, /*Светодиод D2*/
	o_D3 = 1  /*Светодиод D3*/
} tIOLine;

void IO_Init(void);
void IO_ConfigLine(tIOLine, uint8_t, uint8_t);
void IO_SetLine(tIOLine, int);
void IO_InvertLine(tIOLine);
int IO_GetLine(tIOLine);
