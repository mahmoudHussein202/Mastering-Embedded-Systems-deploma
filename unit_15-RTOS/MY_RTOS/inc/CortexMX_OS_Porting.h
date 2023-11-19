/*
 * CortexMX_OS_Porting.h
 *
 *  Created on: Oct 17, 2023
 *      Author: Ahmed & Wessam
 */

#ifndef INC_CORTEXMX_OS_PORTING_H_
#define INC_CORTEXMX_OS_PORTING_H_

#include "core_cm3.h"


extern int _estack ;
extern int _eheap ;
#define MainStackSize	3072

#define OS_Set_PSP(add)				__asm volatile("mov r0,%0 \n\t MSR PSP,r0" : : "r" (add))
#define OS_Get_PSP(add)				__asm volatile("MRS r0,PSP \n\t mov %0,r0" : "=r" (add))

#define OS_Switch_SP_to_PSP			__asm volatile("MRS r0,CONTROL \n\t mov r1,#0x02 \n\t orr r0,r0,r1 \n\t MSR CONTROL,r0")
#define OS_Switch_SP_to_MSP			__asm volatile("MRS r0,CONTROL \n\t mov r1,#0x05 \n\t and r0,r0,r1 \n\t MSR CONTROL,r0")

// Clear Bit 0 CONTROL register
#define OS_Switch_Privileged 		__asm volatile("MRS r3,CONTROL \n\t lsr r3,r3,#0x1 \n\t lsl r3,r3,#0x1 \n\t MSR CONTROL,r3")
// Set Bit 0 CONTROL register
#define OS_Switch_UnPrivileged 	__asm volatile("MRS r3,CONTROL \n\t orr r3,r3,#0x1 \n\t MSR CONTROL,r3")

void Trigger_OS_PendSV();
void Start_Ticker();

#endif /* INC_CORTEXMX_OS_PORTING_H_ */
