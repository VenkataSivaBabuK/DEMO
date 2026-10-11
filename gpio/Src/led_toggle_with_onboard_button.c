
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
		onboard_button.GPIO_Pin_Config.GPIO_PinMode = GPIO_IN_MODE;
		onboard_button.GPIO_Pin_Config.GPIO_PinSpeed  = GPIO_SPEED_FAST;
		onboard_button.GPIO_Pin_Config.GPIO_PinPuPDControl = GPIO_NO_PUPD;

		GPIO_PeriClockControl(GPIOC, ENABLE);
		GPIO_Init(&onboard_button);

	     /*while(1)
	     {
	    	 if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == RESET)
	    	 {
	    		 for(uint32_t i = 0; i < 500000/2; i++);

	    		 GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
	    	 }

	     }*/
		while(1)
		{
		    if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == RESET)
		    {
		        GPIO_WritetoOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
		    }
		    else
		    {
		        GPIO_WritetoOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_RESET);
		    }
		}

		return 0;
	}




