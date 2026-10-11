/*
 * Led_toggle.c
 *
 *  Created on: 27 Jun 2026
 *      Author: Siva
 */
#include "stm32f446xx.h"
/*int main(void)
{
	GPIO_Handle_t gpio_led;
	gpio_led.pGPIOx = GPIOA;
	gpio_led.GPIO_Pin_Config.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpio_led.GPIO_Pin_Config.GPIO_PinMode   = GPIO_OU_MODE;
	gpio_led.GPIO_Pin_Config.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	gpio_led.GPIO_Pin_Config.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpio_led.GPIO_Pin_Config.GPIO_PinPuPDControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpio_led);

     while(1)
     {
    	 GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

    	 for(uint32_t i = 0; i < 500000; i++);
     }

	return 0;
}*/
int main(void)
{
	GPIO_Handle_t gpio_led;
	gpio_led.pGPIOx = GPIOB;
	gpio_led.GPIO_Pin_Config.GPIO_PinNumber = GPIO_PIN_NO_13;
	gpio_led.GPIO_Pin_Config.GPIO_PinMode   = GPIO_OU_MODE;
	gpio_led.GPIO_Pin_Config.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	gpio_led.GPIO_Pin_Config.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpio_led.GPIO_Pin_Config.GPIO_PinPuPDControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&gpio_led);

     while(1)
     {
    	 GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NO_13);

    	 for(uint32_t i = 0; i < 500000; i++);
     }

	return 0;
}
