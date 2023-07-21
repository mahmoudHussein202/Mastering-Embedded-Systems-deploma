/**
 ******************************************************************************
 * @file           : Application.c
 * @author         : Eng. Mahmoud Hussein
 * @brief          : Main program body
 *******************************************************************************/
#include "infrastructure.h"
#include "Cortex_M3_NVIC.h"
#include "STM32F103XX_EXTI.h"
#include "STM32F103_AFIO.h"
#include "STM32F103_GPIO.h"
#include "STM32F103_RCC.h"
int main(void)
{
	/*   Initialization */
	set_bit(RCC_APB2ENR,0);  // enable AFIO
	set_bit(RCC_APB2ENR,2);	 // enable GPIO port A
	set_bit(GPIOA_CRL,2);	 // set PA_pin0 to be input floating mode
	set_bit(GPIOA_CRH,0); 	 // set PA_pin8 to be output
	AFIO_EXTICR1 |= (0000)<<0; // select PA[0] from the EXTI line to control the interrupt line
	Enable_NVIC_Mask(6);	//Enable EXTI0 interrupt line
	Enable_Interrupt_Mask(0); // enable mask to EXTI0
	Enable_Rising_Trigger(0); // interrupt on rising edge
    /* Loop forever */
	for(;;);
}

void EXTI0_IRQHandler()
{
	Clear_pending_Trigger(0);
	toggle_bit(GPIOA_ODR,8);
}


