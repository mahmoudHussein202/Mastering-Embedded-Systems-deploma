/*
 * Scheduler.h
 *
 *  Created on: Oct 17, 2023
 *      Author: Ahmed & Wessam
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "CortexMX_OS_Porting.h"

typedef enum{
	NoError,
	Ready_Queue_init_error,
	Task_exceeded_StackSize
}MYRTOS_errorID;


typedef struct {
	unsigned int Stack_Size;
	unsigned char priority;
	void (*p_TaskEntry)(void); //pointer to Task C Function
	unsigned char AutoStart;
	unsigned int _S_PSP_Task ; //Not Entered by the user
	unsigned int _E_PSP_Task ; //Not Entered by the user
	unsigned int* Current_PSP ; //Not Entered by the user
	char TaskName[30];
	enum {
		Suspend,
		Running,
		Waiting,
		ready
	}TaskState; //Not Entered by the user

	struct {
		enum{
			enable,
			disable
		}Blocking;
		unsigned int Ticks_Count;
	}TimeWaiting;

}Task_ref;












//APIs
MYRTOS_errorID MYRTOS_init();
MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Tref);
void MYRTOS_ActivateTask(Task_ref* Tref);
void MYRTOS_TerminateTask(Task_ref* Tref);
void MYRTOS_StartOS();
void MYRTOS_TaskWait(unsigned int NoTicks, Task_ref* SelfTref);



#endif /* INC_SCHEDULER_H_ */
