/*
 * CortexMX_OS_Porting.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef CORTEXMX_OS_PORTING_H_
#define CORTEXMX_OS_PORTING_H_
#include "ARMCM3.h"
extern int _estack;
extern int _eheap;

#define OS_SET_PSP(add)					__asm volatile("mov r0,%0 \n\t msr PSP,r0 ": : "r"(add))
#define OS_GET_PSP(add)					__asm volatile("mrs r0,PSP \n\t mov %0,r0":"=r"(add))
#define OS_SET_MSP(add)					__asm volatile("mov r0,%0 \n\t msr MSP,r0 ": : "r"(add))
#define OS_GET_MSP(add)					__asm volatile("mrs r0,MSP \n\t mov %0,r0":"=r"(add))
#define OS_SWITCH_SP_to_PSP				__asm volatile("mrs r0,CONTROL \n\t mov r1,#0x02 \n\t orr r0,r0,r1 \n\t msr CONTROL,r0")
#define OS_SWITCH_SP_to_MSP				__asm volatile("mrs r0,CONTROL \n\t mov r1,#0x05 \n\t orr r0,r0,r1 \n\t msr CONTROL,r0")

// clear bit 0 in control register
#define OS_SWITCH_to_privilleged		__asm volatile ("mrs r3,CONTROL \n\t" \
														"lsr r3,r3,#0x01 \n\t"\
														"lsl r3,r3,#0x01 \n\t"\
														"msr CONTROL,r3")

//set bit 0 in control register
#define OS_SWITCH_to_unprivilleged		__asm volatile ("mrs r3,CONTROL \n\t"\
														"orr r3,r3,#0x01 \n\t"\
														"msr CONTROL,r3")


#endif /* CORTEXMX_OS_PORTING_H_ */
