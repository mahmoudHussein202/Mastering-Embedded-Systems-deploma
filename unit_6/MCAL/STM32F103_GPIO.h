#ifndef _STM32F103_GPIO_H_
#define _STM32F103_GPIO_H_
#define GPIOA_Base 0x40010800
#define GPIOB_Base 0x40010c00
#define GPIOC_Base 0x40011000
#define GPIOD_Base 0x40011400
#define GPIOE_Base 0x40011800
#define GPIOF_Base 0x40011C00
#define GPIOG_Base 0x40012000


#define GPIOA_CRL	*((volatile unsigned int *)(GPIOA_Base + 0x00))
#define GPIOA_CRH	*((volatile unsigned int *)(GPIOA_Base + 0x04))
#define GPIOA_ODR	*((volatile unsigned int *)(GPIOA_Base + 0x0C))


#endif
