/*
 * CortexMX_OS_Porting.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Ahmed & Wessam
 */


#include "CortexMX_OS_Porting.h"

unsigned char SysTickLED;

void HardFault_Handler(void)
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

__attribute ((naked)) void SVC_Handler()
{
	__asm("tst lr,#4  \n\t"
			"ITE EQ \n\t"
			"mrseq r0,MSP \n\t"
			"mrsne r0,PSP \n\t"
			"B OS_SVC");
}


void HW_init()
{
	//intialize clock tree (RCC -> SysTick Timer & CPU) 8 MHZ
	//init HW
	//Clock Tree
	//RCC Default values makes CPU Clock & SysTick Timer clock = 8 MHZ

	// 8 MHZ
	// 1 count -> 0.125 us
	// X count -> 1 ms
	// X = 8000 count

	//decrease PendSV interrupt priority to be smaller than or equal SysTick Timer
	//SysTick have a priority 14
	__NVIC_SetPriority(PendSV_IRQn, 15);

}

void Trigger_OS_PendSV()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;

}

void Start_Ticker()
{
	//This clock tree should be defined in HW_init()
	// 8 MHZ
	// 1 count -> 0.125 us
	// X count -> 1 ms =====> X = 8000 count
	SysTick_Config(8000);

}

void SysTick_Handler(void)
{
	SysTickLED ^= 1;
	MYRTOS_Update_TaskWaitingTime();
	//determine Pcurrent & Pnext
	Decide_whatNext();
	//switch Context & restore
	Trigger_OS_PendSV();
}


