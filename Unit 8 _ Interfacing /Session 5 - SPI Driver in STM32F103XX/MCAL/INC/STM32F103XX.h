/*
 * STM32F103XX.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
#include "std_typedef.h"
/**************************** Memory Map  ********************************/
#define RCC_base_address						0x40021000
#define GPIO_port_A_base_address				0x40010800
#define GPIO_port_B_base_address				0x40010C00
#define GPIO_port_C_base_address				0x40011000
#define GPIO_port_D_base_address				0x40011400
#define GPIO_port_E_base_address				0x40011800
#define AFIO_base_address						0x40010000
#define SPI1_base_address						0x40013000
#define SPI2_base_address						0x40003800

#endif /* INC_STM32F103XX_H_ */
