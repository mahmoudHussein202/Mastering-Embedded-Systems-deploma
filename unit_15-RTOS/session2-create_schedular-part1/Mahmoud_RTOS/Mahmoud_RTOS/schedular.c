/*
 * schedular.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mahmoud Hussein
 */
#include "schedular.h"
#include "CortexMX_OS_Porting.h"
#include "fifo.h"
#include "string.h"
//-----------------OS_Control---------------------//
Mahmoud_RTOS_ERROR_ID Mahmoud_RTOS_create_task(Task_ref* new_task_ref);
void MAHMOUD_RTOS_IDLE_TASK();
struct {
	Task_ref* OS_Tasks[100]; //schedular table
	unsigned int _S_MSP_Task;
	unsigned int _E_MSP_Task;
	unsigned int _main_stack_size;
	unsigned int PSP_Task_Locator;
	unsigned int No_of_active_tasks;
	Task_ref* current_task;
	Task_ref* next_task;
	enum {
		OS_susspend,
		OS_running
	}osModeID;

}OS_Control;
fifo_buffer_t Schedular_ready_queue_Status;
element_type Schedular_ready_queue[100];
Task_ref* M_RTOS_Idle_task;

//---------------------------------------------//
void OS_SVC(int* Stack_Frame)
{
	unsigned char svc_number;
	svc_number =  *((unsigned char *)(((unsigned char * )Stack_Frame[6])-2));
	switch (svc_number)
	{
	case 0:
		//create task
		break;
	case 1:
		//terminate task
		break;
	}
}

void Mahmoud_RTOS_Create_main_stack()
{
	OS_Control._main_stack_size = 3024;
	OS_Control._S_MSP_Task = (volatile unsigned int)&_estack;
	OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - OS_Control._main_stack_size ;
	//now align 8 bytes between main stack and the first process stack
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task)-8;
}
Mahmoud_RTOS_ERROR_ID Mahmoud_RTOS_init()
{
	Mahmoud_RTOS_ERROR_ID error = no_error;
	//update OS Mode
	OS_Control.osModeID = OS_susspend;
	//Specify the Main Stack for OS
	Mahmoud_RTOS_Create_main_stack();
	//Create OS ready queue  [ any task in ready state will be in this queue ] - circular FIFO for round robin
	if (fifo_init_F(&Schedular_ready_queue_Status, Schedular_ready_queue, 100)!= fifo_no_error)
	{
		Mahmoud_RTOS_ERROR_ID error = Ready_Queue_init_error;
	}
	//configure IDLE Task
	strcpy(M_RTOS_Idle_task->TaskName,"Idle_Task");
	M_RTOS_Idle_task->priority = 255; // lowest priority
	M_RTOS_Idle_task->p_task_entry = MAHMOUD_RTOS_IDLE_TASK;


	//create task table		[ contain all tasks which is created and have its' own stack , but in suspend state]

	return error;
}
void MAHMOUD_RTOS_IDLE_TASK(){
	while(1)
	{
		__asm("NOP");
	}
}
Mahmoud_RTOS_ERROR_ID Mahmoud_RTOS_create_stack(Task_ref* new_task_ref)
{
	/* Task Frame
	 * ==========
	 * r0
	 * r1
	 * r2
	 * r3
	 * r4
	 * r12
	 * LR (return register which is saved in cpu while task1 running before TaskSwitching
	 * PC (next task instruction which should be run
	 * XPSR
	 * =======
	 * (Manually)
	 * =======
	 * r5
	 * r6
	 * r7
	 * r8
	 * r9
	 * r10
	 * r11
	 */
	new_task_ref->Current_PSP = new_task_ref->_S_PSP_TASK;
	new_task_ref->Current_PSP --;
	*(new_task_ref->Current_PSP) = 0x01000000;  // dummy XPSR where T=1 to avoid bus fault (thread mode bit no 24)
	new_task_ref->Current_PSP --;
	*(new_task_ref->Current_PSP) = new_task_ref->p_task_entry; // first value of pc in the task frame
	new_task_ref->Current_PSP --;
	*(new_task_ref->Current_PSP) = 0XFFFFFFFD; // Execution return // dummy value for the first time
	for ( int j = 0 ; j<13 ; j++)
	{
		new_task_ref->Current_PSP--;
		*(new_task_ref->Current_PSP) = 0;
	}



}

Mahmoud_RTOS_ERROR_ID Mahmoud_RTOS_create_task(Task_ref* new_task_ref)
{
	Mahmoud_RTOS_ERROR_ID error = no_error;
	//check task stack size exceeds the psp stack
	new_task_ref->_S_PSP_TASK = OS_Control.PSP_Task_Locator;
	new_task_ref->_E_PSP_TASK = new_task_ref->_S_PSP_TASK - new_task_ref->Stack_size;
	if (new_task_ref->_E_PSP_TASK < (unsigned int )_eheap)
	{
		return Task_exceeded_stack_size;
	}
	// create  its' own psp stack
	 Mahmoud_RTOS_create_stack(new_task_ref);
	//Allign 8 bit between the two tasks
	 OS_Control.PSP_Task_Locator = (new_task_ref->_E_PSP_TASK - 8 );
	// task state update

}
