#ifndef _RCC_H_
#define _RCC_H_
/*--------------------------Includes----------------------------*/
#include "infrastructure.h"
/*----------------------Define Macros---------------------------*/
#define RCC 0x40021000
#define RCC_CR *((volatile uint32_t*)(RCC + 0x00))
#define RCC_CFGR *((volatile uint32_t*)(RCC + 0x04))
#define RCC_APB2ENR *((volatile uint32_t*)(RCC + 0x18))
/*----------------------Macros Functions ------------------------*/
//[select the clock source]
#define RCC_select_HSI()    set_once(RCC_CFGR,0,0b00)
#define RCC_select_HSE()    set_once(RCC_CFGR,0,0b01)
#define RCC_select_PLL()    set_once(RCC_CFGR,0,0b10)
#define RCC_Enable_PLL()	set_pin(RCC_CR,24)
#define RCC_Enable_PLL()	set_pin(RCC_CR,24)
#define RCC_Enable_PLL()	set_pin(RCC_CR,24)
#define RCC_Enable_PLL()	set_pin(RCC_CR,24)

//-------[Configue the clock prescalars]------------
//[1]AHB_PRESCALAR
#define RCC_AHB_Prescalar_by_1()      set_once(RCC_CFGR,4,0b0000)
#define RCC_AHB_Prescalar_by_2()      set_once(RCC_CFGR,4,0b1000)
#define RCC_AHB_Prescalar_by_4()      set_once(RCC_CFGR,4,0b1001)
#define RCC_AHB_Prescalar_by_8()      set_once(RCC_CFGR,4,0b1010)
#define RCC_AHB_Prescalar_by_16()     set_once(RCC_CFGR,4,0b1011)
#define RCC_AHB_Prescalar_by_64()     set_once(RCC_CFGR,4,0b1100)
#define RCC_AHB_Prescalar_by_128()    set_once(RCC_CFGR,4,0b1101)
#define RCC_AHB_Prescalar_by_256()    set_once(RCC_CFGR,4,0b1110)
#define RCC_AHB_Prescalar_by_512()    set_once(RCC_CFGR,4,0b1111)
//[2]APB1_PRESCALAR
#define RCC_APB1_prescalar_by_1()     set_once(RCC_CFGR,8,0b000)
#define RCC_APB1_prescalar_by_2()     set_once(RCC_CFGR,8,0b100)
#define RCC_APB1_prescalar_by_4()     set_once(RCC_CFGR,8,0b101)
#define RCC_APB1_prescalar_by_8()     set_once(RCC_CFGR,8,0b110)
#define RCC_APB1_prescalar_by_16()    set_once(RCC_CFGR,8,0b111)
//[3]APB2_PRESCALAR
#define RCC_APB2_prescalar_by_1()     set_once(RCC_CFGR,11,0b000)
#define RCC_APB2_prescalar_by_2()     set_once(RCC_CFGR,11,0b100)
#define RCC_APB2_prescalar_by_4()     set_once(RCC_CFGR,11,0b101)
#define RCC_APB2_prescalar_by_8()     set_once(RCC_CFGR,11,0b110)
#define RCC_APB2_prescalar_by_16()    set_once(RCC_CFGR,11,0b111)
//[4]PLL_MUX_Factors
#define RCC_PLLMUX_by_2()			  set_once(RCC_CFGR,18,0b0000)
#define RCC_PLLMUX_by_3()			  set_once(RCC_CFGR,18,0b0001)
#define RCC_PLLMUX_by_4()			  set_once(RCC_CFGR,18,0b0010)
#define RCC_PLLMUX_by_5()			  set_once(RCC_CFGR,18,0b0011)
#define RCC_PLLMUX_by_6()			  set_once(RCC_CFGR,18,0b0100)
#define RCC_PLLMUX_by_7()			  set_once(RCC_CFGR,18,0b0101)
#define RCC_PLLMUX_by_8()			  set_once(RCC_CFGR,18,0b0110)
#define RCC_PLLMUX_by_9()			  set_once(RCC_CFGR,18,0b0111)
#define RCC_PLLMUX_by_10()			  set_once(RCC_CFGR,18,0b1000)
#define RCC_PLLMUX_by_11()			  set_once(RCC_CFGR,18,0b1001)
#define RCC_PLLMUX_by_12()			  set_once(RCC_CFGR,18,0b1010)
#define RCC_PLLMUX_by_13()			  set_once(RCC_CFGR,18,0b1011)
#define RCC_PLLMUX_by_14()			  set_once(RCC_CFGR,18,0b1100)
#define RCC_PLLMUX_by_15()			  set_once(RCC_CFGR,18,0b1101)
#define RCC_PLLMUX_by_16()			  set_once(RCC_CFGR,18,0b1110)

//[Enabling Clock]
#define RCC_AFIO_ENB()    (RCC_APB2ENR|=1<<2)
#define RCC_GPIOA_ENB()   (RCC_APB2ENR|=1<<3)
#define RCC_GPIOB_ENB()   (RCC_APB2ENR|=1<<4)
#define RCC_GPIOC_ENB()   (RCC_APB2ENR|=1<<5)
#define RCC_GPIOD_ENB()   (RCC_APB2ENR|=1<<6)
#define RCC_GPIOE_ENB()   (RCC_APB2ENR|=1<<7)
#define RCC_GPIOF_ENB()   (RCC_APB2ENR|=1<<8)
#define RCC_ADC_1_ENB()   (RCC_APB2ENR|=1<<9)
#define RCC_ADC_2_ENB()   (RCC_APB2ENR|=1<<10)
#define RCC_TIM_1_ENB()   (RCC_APB2ENR|=1<<11)
#define RCC_SPI_ENB()     (RCC_APB2ENR|=1<<12)
#define RCC_TIM_8_ENB()   (RCC_APB2ENR|=1<<13)
#define RCC_USART_ENB()   (RCC_APB2ENR|=1<<14)
#define RCC_ADC_3_ENB()   (RCC_APB2ENR|=1<<15)
#define RCC_TIM_9_ENB()   (RCC_APB2ENR|=1<<19)
#define RCC_TIM_10_ENB()  (RCC_APB2ENR|=1<<20)
#define RCC_TIM_11_ENB()  (RCC_APB2ENR|=1<<21)
#endif
