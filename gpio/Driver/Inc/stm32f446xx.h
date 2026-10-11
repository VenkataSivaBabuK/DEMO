

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_
#include<stdint.h>              //for including uint32//
#define __vo volatile            // all memberes of peripheral structure voltile //
//#define  GPIOA  ((GPIO_Reg_Def_t*)GPIOA_BASEADD)


/// Base address of Processer ARMCortex M4 ****//////


#define NVIC_ISER0   (*((__vo uint32_t *)0xE000E100))
#define NVIC_ISER1   (*((__vo uint32_t *)0xE000E104))
#define NVIC_ISER2   (*((__vo uint32_t *)0xE000E108))

#define NVIC_ICER0   (*((__vo uint32_t *)0xE000E180))
#define NVIC_ICER1   (*((__vo uint32_t *)0xE000E184))
#define NVIC_ICER2   (*((__vo uint32_t *)0xE000E188))


#define NVIC_PR_BASEADDR    ((__vo uint32_t *)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED    4U






/* Base address of Embedded Memories*/

#define FLASH_BASEADDR  0x08000000U          //stores your program code (firmware)//
#define SRAM1_BASEADDR  0x20000000U         //Holds runtime data — stack, heap, global/static variables//
#define SRAM2_BASEADDR  0x2001C000U
#define SRAM            SRAM1_BASEADDR
#define ROM             0x1FFF0000U         // Contains factory-programmed boot loader or fixed routines.//



/*Bus peripheral bas address */

#define PERIPH_BASE           0x40000000U
#define APB1_PERIPH_BASE      PERIPH_BASE
#define APB2_PERIPH_BASE      0x40010000U
#define AHB1_PERIPH_BASE      0x40020000U
#define AHB2_PERIPH_BASE      0x50000000U

/* Base address of peripherals connected to AHB1_BUS */

#define  GPIOA_BASEADD       (AHB1_PERIPH_BASE + 0X0000)
#define  GPIOB_BASEADD       (AHB1_PERIPH_BASE + 0X0400)
#define  GPIOC_BASEADD       (AHB1_PERIPH_BASE + 0X0800)
#define  GPIOD_BASEADD       (AHB1_PERIPH_BASE + 0X0C00)
#define  GPIOE_BASEADD       (AHB1_PERIPH_BASE + 0X1000)
#define  GPIOF_BASEADD       (AHB1_PERIPH_BASE + 0X1400)
#define  GPIOG_BASEADD       (AHB1_PERIPH_BASE + 0X1800)
#define  GPIOH_BASEADD       (AHB1_PERIPH_BASE + 0X1C00)
#define  RCC_BASEADD         (AHB1_PERIPH_BASE + 0X3800)

/* Base address of peripherals connected to APB1_BUS */
                   //I2c//
#define I2C1_BASEADD          (APB1_PERIPH_BASE + 0X5400)
#define I2C2_BASEADD          (APB1_PERIPH_BASE + 0X5800)
#define I2C3_BASEADD          (APB1_PERIPH_BASE + 0X5C00)
                  //UART//
#define USART2_BASEADD        (APB1_PERIPH_BASE + 0X4400)
#define USART3_BASEADD        (APB1_PERIPH_BASE + 0X4800)
#define UART4_BASEADD         (APB1_PERIPH_BASE + 0X4C00)
#define UART5_BASEADD         (APB1_PERIPH_BASE + 0X5000)
                    //SPI//

#define SPI2_BASEADD         (APB1_PERIPH_BASE + 0X3800)
#define SPI3_BASEADD         (APB1_PERIPH_BASE + 0X3C00)

/* Base address of peripherals connected to APB2_BUS */

#define SPI1_BASEADD             (APB2_PERIPH_BASE + 0X3000)
#define SPI4_BASEADD             (APB2_PERIPH_BASE + 0X3400)
#define USART1_BASEADD           (APB2_PERIPH_BASE + 0X4400)
#define USART6_BASEADD           (APB2_PERIPH_BASE + 0x1400)

#define SYSCFG_BASEADD           (APB2_PERIPH_BASE + 0X3800)
#define EXTI_BASEADD             (APB2_PERIPH_BASE + 0X3C00)


/******************* GPIO Register defination structure*******/
typedef struct
{
	 __vo uint32_t MODER ;
	 __vo uint32_t OTYPER ;
	 __vo uint32_t OSPEEDER ;
	 __vo uint32_t PUPDR ;
	 __vo uint32_t IDR ;
	 __vo uint32_t ODR ;
	 __vo uint32_t BSRR ;
	 __vo uint32_t LCKR;
	 __vo uint32_t AFR[2] ;
	 //__vo uint32_t AFRH ;
}GPIO_Reg_Def_t;

//GPIO_Reg_Def_t *pGPIOA  = (GPIO_Reg_Def_t*)GPIOA_BASEADD;//
//GPIO_Reg_Def_t *pGPIOA  = GPIOA;

/******************* SPI Register defination structure*******/
typedef struct
{
	 __vo uint32_t SPI_CR1;
	 __vo uint32_t SPI_CR2;
	 __vo uint32_t SPI_SR;
	 __vo uint32_t SPI_DR;
	 __vo uint32_t SPI_CRCPR;
	 __vo uint32_t SPI_RXCRCR;
	 __vo uint32_t SPI_TXCRCR;
	 __vo uint32_t SPI_I2SCFGR;
	 __vo uint32_t SPI_I2SPR;
}SPI_Reg_Def_t;

#define SPI1 (( SPI_Reg_Def_t*)SPI1_BASEADD)
#define SPI2 (( SPI_Reg_Def_t*)SPI2_BASEADD)
#define SPI3 (( SPI_Reg_Def_t*)SPI3_BASEADD)
#define SPI4 (( SPI_Reg_Def_t*)SPI4_BASEADD)
/*
 * peripheral register definition structure for I2C
 */

typedef struct
{
  __vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
}I2C_RegDef_t;

#define I2C1  ((I2C_RegDef_t*)I2C1_BASEADD )
#define I2C2  ((I2C_RegDef_t*)I2C2_BASEADD )
#define I2C3  ((I2C_RegDef_t*)I2C3_BASEADD )

typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;
} USART_RegDef_t;

//Peripheral defination Peripheral base address typecastes to (GPIO_Reg_Def_t*)//

#define  GPIOA  ((GPIO_Reg_Def_t*)GPIOA_BASEADD)
#define  GPIOB  ((GPIO_Reg_Def_t*)GPIOB_BASEADD)
#define  GPIOC  ((GPIO_Reg_Def_t*)GPIOC_BASEADD)
#define  GPIOD  ((GPIO_Reg_Def_t*)GPIOD_BASEADD)
#define  GPIOE  ((GPIO_Reg_Def_t*)GPIOE_BASEADD)
#define  GPIOF  ((GPIO_Reg_Def_t*)GPIOF_BASEADD)
#define  GPIOG  ((GPIO_Reg_Def_t*)GPIOG_BASEADD)
#define  GPIOH  ((GPIO_Reg_Def_t*)GPIOH_BASEADD)

/******************* RCC Register defination structure*******/
typedef struct
{
__vo uint32_t CR ;
	 __vo uint32_t PLLCFGR ;
	 __vo uint32_t RCC_CFGR ;
	 __vo uint32_t RCC_CIR ;
	 __vo uint32_t AHB1RSTR ;
	 __vo uint32_t AHB2RSTR ;
	 __vo uint32_t AHB3RSTR ;
	 __vo uint32_t Reserved1;
	 __vo uint32_t RCC_APB1RSTR ;
	 __vo uint32_t RCC_APB2RSTR ;
	 __vo uint32_t Reserved2;
	 __vo uint32_t Reserved3;
	 __vo uint32_t AHB1ENR ;
	 __vo uint32_t AHB2ENR ;
	 __vo uint32_t AHB3ENR ;
	 __vo uint32_t Reserved4;
	 __vo uint32_t APB1ENR;
	 __vo uint32_t APB2ENR;
	 __vo uint32_t Reserved5;
	 __vo uint32_t Reserved6;
	 __vo uint32_t AHB1LPENR ;
	 __vo uint32_t AHB2LPENR ;
	 __vo uint32_t AHB3LPENR ;
	 __vo uint32_t Reserved7;
	 __vo uint32_t APB1LPENR ;
	 __vo uint32_t APB2LPENR ;
	 __vo uint32_t Reserved8;
	 __vo uint32_t Reserved9;
	 __vo uint32_t BDCR;
	 __vo uint32_t RCC_CSR;
	 __vo uint32_t Reserved10;
	 __vo uint32_t Reserved11;
	 __vo uint32_t SSCGR;
	 __vo uint32_t PLLI2SCFGR;
	 __vo uint32_t PLLSAICFGR;
	 __vo uint32_t DCKCFGR;
	 __vo uint32_t CKGATENR;
	 __vo uint32_t DCKCFGR2;

}RCC_Reg_Def_t;

//RCC_Reg_Def_t *pRCC = (RCC_Reg_Def_t*)RCC_BASEADD;
//Peripheral defination Peripheral base address typecastes to (RCC_Reg_Def_t*)//
#define   RCC  ((RCC_Reg_Def_t*)RCC_BASEADD)
/******************* EXTI Register defination structure*******/
typedef struct
{
	__vo uint32_t EXTI_IMR ;
	__vo uint32_t EXTI_EMR ;
	__vo uint32_t EXTI_RTSR ;
	__vo uint32_t EXTI_FTSR ;
	__vo uint32_t EXTI_SWIER ;
	__vo uint32_t EXTI_PR;
}EXTI_Reg_Def_t;

#define   EXTI  ((EXTI_Reg_Def_t*)EXTI_BASEADD)
/******************* SYSCFG Register defination structure*******/
typedef struct
{
	__vo uint32_t SYSCFG_MEMRMP;
	__vo uint32_t SYSCFG_PMC;
	__vo uint32_t SYSCFG_EXTICR[4];
	__vo uint32_t SYSCFG_CMPCR;
	__vo uint32_t SYSCFG_CFGR;

}SYSCFG_Reg_Def_t;

#define   SYSCFG  ((SYSCFG_Reg_Def_t*)SYSCFG_BASEADD)

/************************** Clock enable macros for GPIO Peripheral ******************************************************/

#define GPIOA_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 0 ))
#define GPIOB_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 1 ))
#define GPIOC_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 2 ))
#define GPIOD_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 3 ))
#define GPIOE_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 4 ))
#define GPIOF_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 5 ))
#define GPIOG_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 6 ))
#define GPIOH_PCLK_EN()  ((RCC->AHB1ENR)|= (1 << 7 ))


/************************** Clock enable macros for I2C Peripheral ******************************************************/
#define I2C1_CLK_EN    ((RCC->APB1ENR)|= (1 << 21))
#define I2C2_CLK_EN    ((RCC->APB1ENR)|= (1 << 22))
#define I2C3_CLK_EN    ((RCC->APB1ENR)|= (1 << 23))
/************************** Clock enable macros for SPI Peripheral ******************************************************/
#define SPI1_CLK_EN()    ((RCC->APB2ENR)|= (1 << 12))
#define SPI4_CLK_EN()    ((RCC->APB2ENR)|= (1 << 13))
#define SPI2_CLK_EN()    ((RCC->APB1ENR)|= (1 << 14))
#define SPI3_CLK_EN()    ((RCC->APB1ENR)|= (1 << 15))
/************************** Clock enable macros for UART Peripheral ******************************************************/
#define USART1_CLK_EN  ((RCC->APB2ENR)|= (1 << 4))
#define USART6_CLK_EN  ((RCC->APB2ENR)|= (1 << 5))
#define USART2_CLK_EN  ((RCC->APB1ENR)|= (1 << 17))
#define USART3_CLK_EN  ((RCC->APB1ENR)|= (1 << 18))
#define UART4_CLK_EN   ((RCC->APB1ENR)|= (1 << 19))
#define UART5_CLK_EN   ((RCC->APB1ENR)|= (1 << 20))
/************************** Clock enable macros for SYSCLK Peripheral ******************************************************/
#define SYSCFG_CLK_EN()  ((RCC->APB2ENR)|= (1 << 14))

/************************** Clock disable macros for GPIO Peripheral ******************************************************/

#define GPIOA_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 0 ))
#define GPIOB_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 1 ))
#define GPIOC_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 2 ))
#define GPIOD_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 3 ))
#define GPIOE_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 4 ))
#define GPIOF_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 5 ))
#define GPIOG_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 6 ))
#define GPIOH_PCLK_DI()  ((RCC->AHB1ENR) &= ~(1 << 7 ))

/************************** Clock disable macros for I2C Peripheral ******************************************************/
#define I2C1_CLK_DI    ((RCC->APB1ENR) &= ~(1 << 21))
#define I2C2_CLK_DI    ((RCC->APB1ENR) &= ~(1 << 22))
#define I2C3_CLK_DI    ((RCC->APB1ENR) &= ~(1 << 23))
/************************** Clock disable macros for SPI Peripheral ******************************************************/
#define SPI1_CLK_DI()    ((RCC->APB2ENR) &= ~(1 << 12))
#define SPI4_CLK_DI()    ((RCC->APB2ENR) &= ~(1 << 13))
#define SPI2_CLK_DI()    ((RCC->APB1ENR) &= ~(1 << 14))
#define SPI3_CLK_DI()    ((RCC->APB1ENR) &= ~(1 << 15))
/************************** Clock disable macros for UART Peripheral ******************************************************/
#define USART1_CLK_DI  ((RCC->APB2ENR) &= ~(1 << 4))
#define USART6_CLK_DI  ((RCC->APB2ENR) &= ~(1 << 5))
#define USART2_CLK_DI  ((RCC->APB1ENR) &= ~(1 << 17))
#define USART3_CLK_DI  ((RCC->APB1ENR) &= ~(1 << 18))
#define UART4_CLK_DI   ((RCC->APB1ENR) &= ~(1 << 19))
#define UART5_CLK_DI   ((RCC->APB1ENR) &= ~(1 << 20))
/************************** Clock disable macros for SYSCLK Peripheral ******************************************************/
#define SYSCFG_CLK_DI  ((RCC->APB2ENR) &= ~(1<< 14))

/******************  Macros to reset GPIOx peripheral *******************************/

#define GPIOA_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 0 ));(RCC->AHB1RSTR) &= ~(1 << 0 );}while(0)
#define GPIOB_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 1 ));(RCC->AHB1RSTR) &= ~(1 << 1 );}while(0)
#define GPIOC_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 2 ));(RCC->AHB1RSTR) &= ~(1 << 2 );}while(0)
#define GPIOD_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 3 ));(RCC->AHB1RSTR) &= ~(1 << 3 );}while(0)
#define GPIOE_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 4 ));(RCC->AHB1RSTR) &= ~(1 << 4 );}while(0)
#define GPIOF_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 5 ));(RCC->AHB1RSTR) &= ~(1 << 5 );}while(0)
#define GPIOG_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 6 ));(RCC->AHB1RSTR) &= ~(1 << 6 );}while(0)
#define GPIOH_REG_RESET()  do{((RCC->AHB1RSTR) |= (1 << 7 ));(RCC->AHB1RSTR) &= ~(1 << 7 );}while(0)


#define GPIO_PORT_CODE(x)  ( (x == GPIOA)? 0U :\
		                    (x == GPIOB)? 1U :\
		                    (x == GPIOC)? 2U:\
		                    (x == GPIOD)? 3U :\
		                    (x == GPIOE)? 4U :\
		                    (x == GPIOF)? 5U :\
		                    (x == GPIOG)? 6U :\
		                    (x == GPIOH)? 7U : 0U)


/********* IRQ numbers *****/

#define IRQ_NO_EXTI0        6U
#define IRQ_NO_EXTI1        7U
#define IRQ_NO_EXTI2        8U
#define IRQ_NO_EXTI3        9U
#define IRQ_NO_EXTI4        10U
#define IRQ_NO_EXTI9_5      23U
#define IRQ_NO_EXTI15_10    40U


#define SPI2_IRQn   36

#define TIM2_IRQn 28








/****************** Generic Macros *******************************/


#define ENABLE             1
#define DISABLE            0
#define SET               ENABLE
#define RESET             DISABLE
#define GPIO_PIN_SET      SET
#define GPIO_PIN_RESET    RESET
#define FLAG_RESET         RESET
#define FLAG_SET 			SET

/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15
/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8

/******************************************************************************************
 *Bit position definitions of I2C peripheral
 ******************************************************************************************/
/*
 * Bit position definitions I2C_CR1
 */
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/*
 * Bit position definitions I2C_CR2
 */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/*
 * Bit position definitions I2C_OAR1
 */
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*
 * Bit position definitions I2C_SR2
 */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/*
 * Bit position definitions I2C_CCR
 */
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15





#include "stm32f446xx_gpio.h"
#include "stm32f446xx_spi.h"
#include "stm32f446xx_i2c.h"
#include "stm32f446xx_rtc.h"
//#include "w25q32_flash.h"





#endif /* INC_STM32F446XX_H_ */
