/*
 * Int_both_edges.c
 *
 *  Created on: 2 Jul 2026
 *      Author: Work
 */

/*
 * GPIO_int.c
 *
 *  Created on: 2 Jul 2026
 *      Author: Work
 *
 */
#include "stm32f446xx.h"

int main(void)
{
	    GPIO_Handle_t gpio_led,onboard_button;
		gpio_led.pGPIOx = GPIOA;
		gpio_led.GPIO_Pin_Config.GPIO_PinNumber = GPIO_PIN_NO_5;
		gpio_led.GPIO_Pin_Config.GPIO_PinMode   = GPIO_OU_MODE;
		gpio_led.GPIO_Pin_Config.GPIO_PinSpeed  = GPIO_SPEED_FAST;
		gpio_led.GPIO_Pin_Config.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		gpio_led.GPIO_Pin_Config.GPIO_PinPuPDControl = GPIO_NO_PUPD;
		GPIO_PeriClockControl(GPIOA, ENABLE);
		GPIO_Init(&gpio_led);

		onboard_button.pGPIOx = GPIOC;
		onboard_button.GPIO_Pin_Config.GPIO_PinNumber =GPIO_PIN_NO_13;
		onboard_button.GPIO_Pin_Config.GPIO_PinMode = GPIO_MODE_IT_RFT;
		onboard_button.GPIO_Pin_Config.GPIO_PinSpeed  = GPIO_SPEED_FAST;
		onboard_button.GPIO_Pin_Config.GPIO_PinPuPDControl = GPIO_NO_PUPD;

		GPIO_PeriClockControl(GPIOC, ENABLE);
		GPIO_Init(&onboard_button);

		//GPIO_IRQConfig(EXTI15_10_IRQ_NO, ENABLE);
		//GPIO_PR_Config(EXTI15_10_IRQ_NO, 2);
		GPIO_IRQConfig(IRQ_NO_EXTI15_10, ENABLE);
		GPIO_PR_Config(IRQ_NO_EXTI15_10, 2);
		while(1)
		{

		}
}

/*void EXTI15_10_IRQHandler(void)
{

    if(EXTI->EXTI_PR & (1 << 13))
    {
        EXTI->EXTI_PR |= (1 << 13);   // try |= instead of =
    }

    GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
}*/
void EXTI15_10_IRQHandler(void)
{
    GPIO_IRQHandling(GPIO_PIN_NO_13);
      if(GPIO_ReadFromInputPin(GPIOC,13) == RESET )
        {
    	 GPIO_WritetoOutputPin(GPIOA, 5,SET);
        }
        else
        {
        	 GPIO_WritetoOutputPin(GPIOA, 5,RESET);
            // Turn LED OFF
        }

    //GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
}

