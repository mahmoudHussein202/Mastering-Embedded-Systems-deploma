/*
 * STM32F103XX_GPIO.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Mahmoud Hussein
 */
#include "STM32F103XX_GPIO.h"
#include "STM32F103XX.h"
/*********************************************************************
 * Configure the mode of the GPIO pins
 * params : GPIOX  choose the GPIO Port from @ref GPIO_PORTS
 * 			pin_num : choose from pin 0 to pin 15 in each port
 * 			pin_mode: choose input or output mode from @ref GPIO_mode
 * 			mode_type : if output mode : @ref GPIO_output_mode_type
 * 						if input mode :  @ref GPIO_input_mode_type
 **********************************************************************/
void GPIO_set_pin_mode(GPIO_typedef * GPIOx , uint8_t pin_num ,uint8_t mode, uint8_t mode_type)
{
	uint8_t CNF_MODE = mode_type | mode ;
	uint8_t CNF_MODE_Invert = ~(CNF_MODE);

	if (pin_num <=7)
	{
		uint8_t real_shift = pin_num*4;
		GPIOx->GPIO_CRL |= (CNF_MODE << real_shift);
		GPIOx->GPIO_CRL &= ~(CNF_MODE_Invert <<real_shift);
	}
	else if ( pin_num > 7)
	{
		uint8_t pin_num_modified = pin_num - 8 ;
		uint8_t real_shift = pin_num_modified*4;
		GPIOx->GPIO_CRH |= (CNF_MODE << real_shift);
		GPIOx->GPIO_CRH &= ~(CNF_MODE_Invert <<real_shift);
	}

}


