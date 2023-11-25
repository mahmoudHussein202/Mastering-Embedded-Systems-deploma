/*
 * STM32F103XX_RCC.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef INC_STM32F103XX_RCC_H_
#define INC_STM32F103XX_RCC_H_
#include "STM32F103XX.h"
/***********************************************************
 ---------------Configurations and Registers---------------
 ***********************************************************/
typedef struct
{
	uint32_t	RCC_CR;
	uint32_t	RCC_CFGR;
	uint32_t	RCC_CIR;
	uint32_t	RCC_APB2RSTR;
	uint32_t	RCC_APB1RSTR;
	uint32_t	RCC_AHBENR;
	uint32_t	RCC_APB2ENR;
	uint32_t	RCC_APB1ENR;
	uint32_t	RCC_BDCR;
	uint32_t	RCC_CSR;
}RCC_typedef;
/***********************************************************
 -------------------Registers Instants----------------------
 ***********************************************************/
#define	RCC_REG		((RCC_typedef*)RCC_base_address)
/***********************************************************
 ------------------- Clock Enables ----------------------
 ***********************************************************/
//[1] APB1 Bus
#define RCC_SPI2_clk_EN	(	(RCC_REG->RCC_APB1ENR)|= 1<<14)
//[2] APB2 Bus
#define RCC_AFIO_clk_EN		((RCC_REG->RCC_APB2ENR)|= 1<<0)
#define RCC_GPIOA_clk_EN	((RCC_REG->RCC_APB2ENR)|= 1<<2)
#define RCC_GPIOB_clk_EN	((RCC_REG->RCC_APB2ENR)|= 1<<3)
#define RCC_GPIOC_clk_EN	((RCC_REG->RCC_APB2ENR)|= 1<<4)
#define RCC_GPIOD_clk_EN	((RCC_REG->RCC_APB2ENR)|= 1<<5)
#define RCC_GPIOE_clk_EN	((RCC_REG->RCC_APB2ENR)|= 1<<6)
#define RCC_SPI1_clk_EN		(((RCC_REG->RCC_APB2ENR)|= 1<<12))

#endif /* INC_STM32F103XX_RCC_H_ */
