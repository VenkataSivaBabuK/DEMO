/*
 * STM32F446xx_gpio.c
 *
 *  Created on: 26 Jun 2026
 *      Author: Work
 */

#include "stm32f446xx_gpio.h"

/****Periphral clock setup***/
void GPIO_PeriClockControl(GPIO_Reg_Def_t *pGPIOx,uint8_t EnorDe)
{
	if(EnorDe == ENABLE)
	{
		if(pGPIOx == GPIOA )
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if (pGPIOx == GPIOF)
		       {
			        GPIOF_PCLK_EN();
		       }
		else if (pGPIOx == GPIOG)
				{
					GPIOG_PCLK_EN();
				}
		else if (pGPIOx == GPIOH)
				{
					GPIOH_PCLK_EN();
				}


	}
	else
	{

				if(pGPIOx == GPIOA )
				{
					GPIOA_PCLK_DI();
				}
				else if (pGPIOx == GPIOB)
				{
					GPIOB_PCLK_DI();
				}
				else if (pGPIOx == GPIOC)
				{
				  GPIOC_PCLK_DI();
				}
				else if (pGPIOx == GPIOD)
				{
				GPIOD_PCLK_DI();
				}
				else if (pGPIOx == GPIOE)
								{
								GPIOE_PCLK_DI();
								}
				else if (pGPIOx == GPIOF)
								{
								GPIOF_PCLK_DI();
								}
				else if (pGPIOx == GPIOG)
								{
								GPIOG_PCLK_DI();
								}
				else if (pGPIOx == GPIOH)
								{
								GPIOH_PCLK_DI();
								}



	}
}



/****Init & DeInit***/

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle )
{
	GPIO_PeriClockControl(pGPIO_Handle->pGPIOx, ENABLE);
	//1.Configure the mode of gpio pin
    uint32_t tmp = 0;
	if(pGPIO_Handle->GPIO_Pin_Config.GPIO_PinMode <= GPIO_ANALOG_MODE )
	{

		tmp = (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinMode << (2  * (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber)));
		pGPIO_Handle->pGPIOx->MODER &= ~(0x3 <<  (2 *pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		pGPIO_Handle->pGPIOx->MODER |= tmp ;
	}
	else
	{
		if(pGPIO_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			// 1. Configure FTSR

			EXTI->EXTI_FTSR |= (1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
			EXTI->EXTI_RTSR &= ~(1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);

		}
		else if (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			// 2. Configure RTSR
			EXTI->EXTI_RTSR |= (1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
			EXTI->EXTI_FTSR &= ~(1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
		}
		else if (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			// 1. Configure RTSR & RTSR
			EXTI->EXTI_FTSR |= (1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
			EXTI->EXTI_RTSR |= (1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
		}

		// 2. Configure GPIO port selection on SYSCFG

		uint8_t var1 =0,var2 = 0;
		var1 = pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber /4;
		var2 = pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber %4;
		SYSCFG_CLK_EN();
		uint8_t portcode = GPIO_PORT_CODE(pGPIO_Handle->pGPIOx);
		SYSCFG->SYSCFG_EXTICR[var1] &= ~(0xF << (var2 *4));
		SYSCFG->SYSCFG_EXTICR[var1] |= portcode << (var2 *4);


		// 3. Enable EXIT Delivery on IMR
		EXTI->EXTI_IMR |= (1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
}
	tmp = 0;
	//2.Configure the Speed of gpio pin
	tmp = (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinSpeed << (2  * (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber)));
	pGPIO_Handle->pGPIOx->OSPEEDER &= ~(0x3 << (2 *pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->OSPEEDER |= tmp;
	tmp = 0;

	//3.Configure the Pullup & pulldown  of gpio
	tmp = (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinPuPDControl << (2  * (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber)));
	pGPIO_Handle->pGPIOx->PUPDR &= ~(0x3 <<  (2 *pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->PUPDR |= tmp;

	tmp = 0;

	//4.Configure the Output type
		tmp = (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinOPType <<  (pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber))	;
	pGPIO_Handle->pGPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber);
	pGPIO_Handle->pGPIOx->OTYPER |= tmp;
	tmp = 0;

	//5.Configure the alternate function mode
	if(pGPIO_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_ALT_MODE)
	{
		//configure the alt function registers.
		uint8_t temp1, temp2;
		temp1 = pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber / 8 ;
		temp2 = pGPIO_Handle->GPIO_Pin_Config.GPIO_PinNumber % 8;
		pGPIO_Handle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIO_Handle->pGPIOx->AFR[temp1] |=(pGPIO_Handle->GPIO_Pin_Config.GPIO_PinAltFunMode << (4 * temp2));



	}

}
void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx)
{


			if(pGPIOx == GPIOA )
			{
				GPIOA_REG_RESET();
			}
			else if (pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();
			}
			else if (pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();
			}
			else if (pGPIOx == GPIOD)
			{
				GPIOD_REG_RESET();
			}
			else if (pGPIOx == GPIOE)
			{
				GPIOE_REG_RESET();
			}
			else if (pGPIOx == GPIOF)
			       {
				GPIOF_REG_RESET();
			       }
			else if (pGPIOx == GPIOG)
					{
				GPIOG_REG_RESET();
					}
			else if (pGPIOx == GPIOH)
					{
				GPIOH_REG_RESET();
					}
		}


/****Data Read & Write***/
uint8_t GPIO_ReadFromInputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)(pGPIOx->IDR >> PinNumber)& (0x00000001);
    return value;
}

uint16_t GPIO_ReadFromInputPort(GPIO_Reg_Def_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

void GPIO_WritetoOutputPin(GPIO_Reg_Def_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);

	}

	//pGPIOx->ODR |= (1 << PinNumber);
	//pGPIOx->ODR &= ~(1 << PinNumber);
}
void GPIO_WritetoOutputPort(GPIO_Reg_Def_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/****IRQ Config & ISR Handling***/
void GPIO_IRQConfig(uint8_t IRQ_NUM, uint8_t EnorDe)
{

	    if(EnorDe == ENABLE)
	    {
	        if(IRQ_NUM < 32)
	        {
	            NVIC_ISER0 |= (1U << IRQ_NUM);
	        }
	        else if(IRQ_NUM < 64)
	        {
	            NVIC_ISER1 |= (1U << (IRQ_NUM % 32));
	        }
	        else if(IRQ_NUM < 96)
	        {
	            NVIC_ISER2 |= (1U << (IRQ_NUM % 32));
	        }
	    }
	    else
	    {
	        if(IRQ_NUM < 32)
	        {
	            NVIC_ICER0 |= (1U << IRQ_NUM);
	        }
	        else if(IRQ_NUM < 64)
	        {
	            NVIC_ICER1 |= (1U << (IRQ_NUM % 32));
	        }
	        else if(IRQ_NUM < 96)
	        {
	            NVIC_ICER2 |= (1U << (IRQ_NUM % 32));
	        }
	    }


	}

void GPIO_PR_Config(uint8_t IRQ_NUM, uint8_t Priority)
{
    uint8_t iprx = IRQ_NUM / 4;
    uint8_t iprx_section = IRQ_NUM % 4;

    uint8_t shift_amount = (8U * iprx_section) +
                           (8U - NO_PR_BITS_IMPLEMENTED);

    /* Clear implemented priority bits */
    NVIC_PR_BASEADDR[iprx] &= ~(0x0FU << shift_amount);

    /* Set new priority */
    NVIC_PR_BASEADDR[iprx] |= ((Priority & 0x0FU) << shift_amount);
}


void GPIO_IRQHandling(uint8_t PinNumber)
{

	    if(EXTI->EXTI_PR & (1U << PinNumber))
	    {
	        /* Write 1 to clear pending bit */
	        EXTI->EXTI_PR = (1U << PinNumber);
	    }

}

