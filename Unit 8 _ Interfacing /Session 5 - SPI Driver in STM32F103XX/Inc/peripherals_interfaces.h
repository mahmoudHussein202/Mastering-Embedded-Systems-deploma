/*
 * peripherals_interfaces.h
 *
 *  Created on: Nov 26, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef PERIPHERALS_INTERFACES_H_
#define PERIPHERALS_INTERFACES_H_

#define set_bit(module_address,pin_num)			(*(module_address) |=1<<pin_num)
#define clear_bit(module_address,pin_num)		(*(module_address) &= ~(1<<pin_num))
#define toggle_bit(module_address,pin_num)		(*(module_address) ^= 1<<pin_num)
#define set_bits_once(module,first_position,value)		{\
																uint8_t value_invert = ~(value);\
																((module)|=value<<first_position);\
																((module)&=~(value_invert<<first_position));\
																}

#endif /* PERIPHERALS_INTERFACES_H_ */
