#include <gpio_stm32f1.h>

const tGPIO_Line IOs[] = {

	{GPIOB, 13, OUT_50MHz + OUT_PP, HIGH}, /*Светодиод D2*/
	{GPIOB, 14, OUT_50MHz + OUT_PP, HIGH}  /*Светодиод D3*/
};

const uint32_t cIO_COUNT = sizeof(IOs) / sizeof(tGPIO_Line);

void IO_Init(void)
{
	/*RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	/*RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;*/
	/*RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;*/
	/*RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;*/
	/*RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;*/
	/*RCC->APB2ENR |= RCC_APB2ENR_IOPGEN;*/

	/*RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;*/

	// В цикле пробегаемся по нашему массиву и конфигурируем.
	for (int Line = 0; Line < cIO_COUNT; Line++)
	{
		IO_ConfigLine(Line, IOs[Line].MODE, IOs[Line].DefState);
	}
}

void IO_ConfigLine(tIOLine Line, uint8_t Mode, uint8_t State)
{
	if (IOs[Line].GPIO_Pin < 8) // Определяем в старший или младший регистр надо запихивать данные.
	{
		IOs[Line].GPIOx->CRL &= ~(0x0F << (IOs[Line].GPIO_Pin * 4)); // Стираем биты
		IOs[Line].GPIOx->CRL |= Mode << (IOs[Line].GPIO_Pin * 4);	 // Вносим нашу битмаску, задвинув ее на нужное место.
	}
	else
	{
		IOs[Line].GPIOx->CRH &= ~(0x0F << ((IOs[Line].GPIO_Pin - 8) * 4)); // Аналогично для старшего регистра.
		IOs[Line].GPIOx->CRH |= Mode << ((IOs[Line].GPIO_Pin - 8) * 4);
	}

	IOs[Line].GPIOx->ODR &= ~(1 << IOs[Line].GPIO_Pin); // Прописываем ODR, устанавливая состояние по умолчанию.
	IOs[Line].GPIOx->ODR |= State << IOs[Line].GPIO_Pin;
}

void IO_SetLine(tIOLine Line, int State)
{
	if (State)
	{
		IOs[Line].GPIOx->BSRR = 1 << IOs[Line].GPIO_Pin;
	}
	else
	{
		IOs[Line].GPIOx->BRR = 1 << IOs[Line].GPIO_Pin;
	}
}

void IO_InvertLine(tIOLine Line)
{
	IOs[Line].GPIOx->ODR ^= 1 << IOs[Line].GPIO_Pin;
}

int IO_GetLine(tIOLine Line)
{
	if (Line < cIO_COUNT)
		return ((IOs[Line].GPIOx->IDR) & (1 << IOs[Line].GPIO_Pin));
	else
		return 0;
}
