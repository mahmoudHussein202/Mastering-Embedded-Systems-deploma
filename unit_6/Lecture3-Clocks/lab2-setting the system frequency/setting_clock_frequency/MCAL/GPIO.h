#ifndef _GPIO_H_
#define _GPIO_H_
#define GPIOA_Base 0x40010800
#define GPIOA_CRH *((volatile uint32_t*)(GPIOA_Base + 0x04))
#define GPIOA_ODR *((volatile uint32_t*)(GPIOA_Base+0x0C))
#endif