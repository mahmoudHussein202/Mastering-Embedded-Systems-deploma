/*
 * STM32F103XX_GPIO.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef INC_STM32F103XX_GPIO_H_
#define INC_STM32F103XX_GPIO_H_
#include "STM32F103XX.h"
/***********************************************************
 ------------------------references-------------------------
 ***********************************************************/
//@ref GPIO_input_mode_type
#define GPIO_Mode_Analog				0b00
#define GPIO_Mode_Floating				0b01
#define GPIO_Mode_input_pull_up_down	0b10
//@ref GPIO_output_mode_type
#define GPIO_Mode_push_pull				0b00
#define GPIO_Mode_open_drain			0b01
#define AFIO_Mode_push_pull				0b10
#define AFIO_Mode_open_drain			0b11
//@ref GPIO_mode
#define GPIO_input_mode					0b00
#define GPIO_Mode_outout_10MHZ			0b01
#define GPIO_Mode_outout_2MHZ			0b10
#define GPIO_Mode_outout_50MHZ			0b11
/***********************************************************
 ---------------Configurations and Registers---------------
 ***********************************************************/
typedef struct
{
	uint32_t	GPIO_CRL;
	uint32_t	GPIO_CRH;
	uint32_t	GPIO_IDR;
	uint32_t	GPIO_ODR;
	uint32_t	GPIO_BSRR;
	uint32_t	GPIO_BRR;
	uint32_t	GPIO_LCKR;
}GPIO_typedef;
/***********************************************************
 --------------------Peripheral instants-------------------
 ***********************************************************/
//@ref GPIO_PORTS
#define GPIO_A	((GPIO_typedef*)GPIO_port_A_base_address)
#define GPIO_B	((GPIO_typedef*)GPIO_port_B_base_address)
#define GPIO_C	((GPIO_typedef*)GPIO_port_C_base_address)
#define GPIO_D	((GPIO_typedef*)GPIO_port_D_base_address)
#define GPIO_E	((GPIO_typedef*)GPIO_port_E_base_address)

/***********************************************************
 --------------------------APIs----------------------------
 ***********************************************************/
void GPIO_set_pin_mode(GPIO_typedef * GPIOx , uint8_t pin_num ,uint8_t mode, uint8_t mode_type);
#endif /* INC_STM32F103XX_GPIO_H_ */
