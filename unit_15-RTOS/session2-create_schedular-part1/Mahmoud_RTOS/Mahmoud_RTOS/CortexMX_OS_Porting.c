/*
 * CortexMX_OS_Porting.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mahmoud Hussein
 */
#include "CortexMX_OS_Porting.h"

void HardFault_Handler (void)
{
	while(1);
}
void MemManage_Handler(void)
{
	while(1);

}
void BusFault_Handler(void)
{
	while(1);

}
void UsageFault_Handler(void)
{
	while(1);

}
void PendSV_Handler(void)
{
	//clear PendSV
	// SCB->ICSR |= SCB_ICSR_PENDSVCLR_MSK
}
__attribute ((naked)) void SVC_Handler()
{
	__asm(  "tst lr,#4 \n\t"
			"ITE EQ \n\t"
			"mrseq r0,MSP \n\t"
			"mrsne r0,PSP \n\t"
			"B OS_SVC");
}

void Hardware_init()
{
	// initialize clock tree (RCC-> SysTick timer & CPU ) 8MHZ
	// 8 MHZ 'by default this is the default speed'
	// 1 count -> 0.125 us
	// X count -> 1 ms
	// X = 8000 count
}
