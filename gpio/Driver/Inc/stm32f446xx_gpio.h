
#include "stm32f446xx.h"
#ifndef INC_STM32F446XX_GPIO_H_
#define INC_STM32F446XX_GPIO_H_

/**********************Configuration structure for GPIO Pin *****************/
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPDControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;


}GPIO_Pin_Config_t;


/**********************Handler structure for GPIO Pin *****************/
typedef struct
{
	GPIO_Reg_Def_t *pGPIOx;
	GPIO_Pin_Config_t GPIO_Pin_Config;
}GPIO_Handle_t;

/*
   GPIO PIN POSSIBLE MODES
 */

#define GPIO_IN_MODE       0
#define GPIO_OU_MODE       1
#define GPIO_ALT_MODE      2
#define GPIO_ANALOG_MODE   3
#define GPIO_MODE_IT_FT    4
#define GPIO_MODE_IT_RT    5
#define GPIO_MODE_IT_RFT   6


/*
 GPIO PIN POSSIBLE OUTPUT TYPES
 */
#define GPIO_OP_TYPE_PP       0
#define GPIO_OP_TYPE_0D       1
/*
 GPIO PIN POSSIBLE OUTPUT SPEEDS
 */

#define GPIO_SPEED_LOW      0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST     2
#define GPIO_SPEED_HIGH     3

/*
 GPIO PULLUP & PULLDOWN CONFIG REG   */

#define GPIO_NO_PUPD         0
#define GPIO_PIN_PU          1
#define GPIO_PIN_PD          2

/*****GPIO PIN NUMBERS   ******/

#define GPIO_PIN_NO_0         0
#define GPIO_PIN_NO_1         1
#define GPIO_PIN_NO_2         2
#define GPIO_PIN_NO_3         3
#define GPIO_PIN_NO_4         4
#define GPIO_PIN_NO_5         5
#define GPIO_PIN_NO_6         6
#define GPIO_PIN_NO_7         7
#define GPIO_PIN_NO_8         8
#define GPIO_PIN_NO_9         9
#define GPIO_PIN_NO_10        10
#define GPIO_PIN_NO_11        11
#define GPIO_PIN_NO_12        12
#define GPIO_PIN_NO_13        13
#define GPIO_PIN_NO_14        14
#define GPIO_PIN_NO_15        15














/****API For GPIO DRIVER***/

/****Periphral clock setup***/
void GPIO_PeriClockControl(GPIO_Reg_Def_t *pGPIOx ,uint8_t EnorDe);



/****Init & DeInit***/

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle_t );
void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx);

/****Data Read & Write***/
uint8_t GPIO_ReadFromInputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_Reg_Def_t *pGPIOx);
void GPIO_WritetoOutputPin(GPIO_Reg_Def_t *pGPIOx,uint8_t PinNumber,uint8_t Value);
void GPIO_WritetoOutputPort(GPIO_Reg_Def_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber);

/****IRQ Config & ISR Handling***/
void GPIO_IRQConfig(uint8_t IRQ_NUM, uint8_t EnorDe);
void GPIO_PR_Config(uint8_t IRQ_NUM, uint8_t Priority);
void GPIO_IRQHandling(uint8_t PinNumber);






#endif /* INC_STM32F446XX_GPIO_H_ */
