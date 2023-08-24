/*
 * schedular.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_
#include "CortexMX_OS_Porting.h"
#include "stdlib.h"
//--------------------------------
typedef enum {
	no_error,
	Ready_Queue_init_error,
	Task_exceeded_stack_size
}Mahmoud_RTOS_ERROR_ID;
//-------------------------------
typedef struct {
	unsigned int Stack_size;
	unsigned char priority;
	void(*p_task_entry)(void); // pointer to the task c function
	unsigned char Autostart;
	unsigned int _S_PSP_TASK; // not entered by user
	unsigned int _E_PSP_TASK; // not entered by user
	unsigned int * Current_PSP; // not entered by user
	char TaskName[30];
	enum{
		suspend,
		waiting,
		ready,
		running
	}Task_states;
	struct{
		enum{
			block_enable,
			block_disable
		}blocking;
		unsigned int Ticks_count;
	}time_waiting;
}Task_ref;
//--------------------------------------------------------------------


//APIs
Mahmoud_RTOS_ERROR_ID Mahmoud_RTOS_init();
Mahmoud_RTOS_ERROR_ID Mahmoud_RTOS_create_task(Task_ref* new_task_ref);



#endif /* SCHEDULAR_H_ */
