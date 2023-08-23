#ifndef _NVIC_H_
#define _NVIC_H_

#define NVIC_Base 0xE000E100
#define NVIC_ISER0	*((volatile unsigned int *)(NVIC_Base))
#endif
