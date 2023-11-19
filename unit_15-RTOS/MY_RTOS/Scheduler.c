/*
 * Scheduler.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Ahmed & Wessam
 */

#include "Scheduler.h"
#include "MYRTOS_FIFO.h"

struct {
	Task_ref* OSTasks[100]; //Scheduler Table
	unsigned int _S_MSP_Task;
	unsigned int _E_MSP_Task;
	unsigned int PSP_Task_Locator;
	unsigned int NoOfActiveTasks;
	Task_ref* CurrentTask;
	Task_ref* NextTask;
	enum{
		OSsuspend,
		OSrunning
	}OSmodeID;

}OS_Control;

typedef enum {
	SVC_ActivateTask,
	SVC_TerminateTask,
	SVC_TaskWaitingTime
}SVC_ID;

FIFO_Buf_t Ready_Queue;
Task_ref* Ready_Queue_FIFO[100];
Task_ref MYRTOS_idleTask ;
unsigned char IdleTaskLED;

__attribute ((naked)) void PendSV_Handler ()
{
	//====================================
	//Save the Context of the Current Task
	//====================================
	//Get the Current Task "Current PSP from CPU register" as CPU Push XPSR,......,R0
	OS_Get_PSP(OS_Control.CurrentTask->Current_PSP);

	///using this current_PSP (pointer) to store (R4 to R11)
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r4" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r5" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r6" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r7" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r8" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r9" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r10" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile("mov %0,r11" : "=r" (*(OS_Control.CurrentTask->Current_PSP)) );

	//save the current value of PSP (already saved in Current_PSP)


	//====================================
	//Save the Context of the Current Task
	//====================================
	OS_Control.CurrentTask = OS_Control.NextTask ;
	OS_Control.NextTask = NULL;

	__asm volatile("mov r11,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r10,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r9,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r8,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r7,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r6,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r5,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;
	__asm volatile("mov r4,%0" : : "r" (*(OS_Control.CurrentTask->Current_PSP)) );
	OS_Control.CurrentTask->Current_PSP++;

	//update PSP and exit
	OS_Set_PSP(OS_Control.CurrentTask->Current_PSP);
	__asm volatile("BX LR");

}

void MYRTOS_Idle_Task()
{
	while (1)
	{
		IdleTaskLED ^= 1;
		__asm("wfe");
	}
}


void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP_Task = &_estack;
	OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - MainStackSize;
	//Aligned 8 Bytes spaces between main task and PSP tasks
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task - 8 );

	//if (_E_MSP_Task < &_eheap) Error:excedded the available stack size
}



MYRTOS_errorID MYRTOS_init()
{
	MYRTOS_errorID error = NoError ;

	//Update OS Mode (OSsuspend)
	OS_Control.OSmodeID = OSsuspend;

	//Specify the Main Stack for OS
	MYRTOS_Create_MainStack();

	//Create OS Ready Queue
	if (FIFO_init(&Ready_Queue, Ready_Queue_FIFO, 100) != FIFO_NO_ERROR)
		error += Ready_Queue_init_error;

	//Configure IDLE Task
	strcpy (MYRTOS_idleTask.TaskName , "idleTask");
	MYRTOS_idleTask.priority = 255;
	MYRTOS_idleTask.p_TaskEntry = MYRTOS_Idle_Task ;
	MYRTOS_idleTask.Stack_Size = 300;

	error += MYRTOS_CreateTask(&MYRTOS_idleTask);




	return error ;

}


void MyRTOS_Create_Task_Stack(Task_ref* Tref)
{
	//Task Frame
	/* ====================
	 * XPSR
	 * PC
	 * LR
	 * r12
	 * r4,r3,r2,r1,r0
	 * =====================
	 * r5,r6,r7,r8,r9,r11 (Saved/Restore) Manual
	 */
	Tref->Current_PSP = Tref->_S_PSP_Task ;

	Tref->Current_PSP--;
	*(Tref->Current_PSP) = 0x01000000; // DUMMY_XPSR should T = 1 to avoid BUS fault

	Tref->Current_PSP--;
	*(Tref->Current_PSP) = (unsigned int)Tref->p_TaskEntry ; //PC

	Tref->Current_PSP--; //LR = 0xFFFFFFFD (EXC_RETURN) Return to thread and PSP stack
	*(Tref->Current_PSP) = 0xFFFFFFFD ;

	for (int j=0; j<13;j++)
	{
		Tref->Current_PSP--;
		*(Tref->Current_PSP) = 0;
	}


}




MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Tref)
{
	MYRTOS_errorID error = NoError ;

	//Create its own PSP stack
	//Check task stack size exceeded the PSP stack
	Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	Tref->_E_PSP_Task = Tref->_S_PSP_Task - Tref->Stack_Size;

	//	-					-
	//	- _S_PSP_Task		-
	//	- Task stack		-
	//	- _E_PSP_Task		-
	//	-					-
	//	- _eheap			-
	//	-					-
	if(Tref->_E_PSP_Task < (unsigned int) (&(_eheap)))
	{
		return Task_exceeded_StackSize;
	}

	//Aligned 8 Bytes spaces between Task PSP and other
	OS_Control.PSP_Task_Locator = (Tref->_E_PSP_Task - 8 );

	//Initialize PSP Task stack
	MyRTOS_Create_Task_Stack(Tref);

	//update sch Table
	OS_Control.OSTasks[OS_Control.NoOfActiveTasks] = Tref;
	OS_Control.NoOfActiveTasks++;

	//Task State Update -> Suspend
	Tref->TaskState = Suspend;

	return error ;

}

//Handler Mode
void bubblesort()
{
	unsigned int i,j,n;
	Task_ref* temp;
	n = OS_Control.NoOfActiveTasks;
	for (i=0 ; i<n-1 ; i++)
		for (j=0 ; j<n-i-1 ; j++)
			if(OS_Control.OSTasks[j]->priority > OS_Control.OSTasks[j+1]->priority)
			{
				temp = OS_Control.OSTasks[j];
				OS_Control.OSTasks[j] = OS_Control.OSTasks[j+1];
				OS_Control.OSTasks[j+1] = temp;
			}
}


//Handler Mode
void MYRTOS_Update_Scheduler_Table()
{
	Task_ref* temp = NULL;
	Task_ref* Ptask;
	Task_ref* PnextTask;
	int i =0;

	//1- bubble sort SchTable OS_Control-> OSTASKS[100] (priority high then low)
	bubblesort();

	//2- free ready queue
	while(FIFO_dequeue(&Ready_Queue, &temp) != FIFO_EMPTY);

	//3- update ready queue
	while(i < OS_Control.NoOfActiveTasks)
	{
		Ptask = OS_Control.OSTasks[i];
		PnextTask = OS_Control.OSTasks[i+1];
		if(Ptask->TaskState != Suspend)
		{
			//in case we reached to the end of available OSTASKS
			if(PnextTask->TaskState == Suspend)
			{
				FIFO_enqueue(&Ready_Queue, Ptask);
				Ptask->TaskState = ready;
				break;
			}
			//if the Ptask priority > next task then (lowest number is meaning higher priority)
			if(Ptask->priority < PnextTask->priority)
			{
				FIFO_enqueue(&Ready_Queue, Ptask);
				Ptask->TaskState = ready;
				break;
			}else if(Ptask->priority == PnextTask->priority)
			{
				//if the Ptask priority == next task then push Ptask to ready state
				//make the Ptask = next task and nexttask++
				FIFO_enqueue(&Ready_Queue, Ptask);
				Ptask->TaskState = ready;
			}else if (Ptask->priority > PnextTask->priority)
			{
				//not allowed to happen as we already reordered it by bubble sort
				break;
			}

		}
		i++;
	}


}


//Handler Mode
void Decide_whatNext()
{
	//if ready queue is empty && OS_Control->CurrentTask != suspend
	if(Ready_Queue.counter == 0 && OS_Control.CurrentTask->TaskState != Suspend)
	{
		OS_Control.CurrentTask->TaskState = Running;
		//add the current task again (round robin)
		FIFO_enqueue(&Ready_Queue, OS_Control.CurrentTask);
		OS_Control.NextTask = OS_Control.CurrentTask;
	}else
	{
		FIFO_dequeue(&Ready_Queue, &OS_Control.NextTask);
		OS_Control.NextTask->TaskState = Running;
		//update ready queue (to keep round robin algorithm happen)
		if((OS_Control.CurrentTask->priority == OS_Control.NextTask->priority) && (OS_Control.CurrentTask->TaskState != Suspend))
		{
			FIFO_enqueue(&Ready_Queue, OS_Control.CurrentTask);
			OS_Control.CurrentTask->TaskState = ready;
		}
	}

}




//Handler Mode
void OS_SVC(int* StackFramePointer)
{
	//r0,r1,r2,r3,r12,LR,PC,XPSR
	unsigned char SVC_Number;
	SVC_Number = *((unsigned char*)(((unsigned char*)StackFramePointer[6])-2)) ;

	switch (SVC_Number)
	{
	case SVC_ActivateTask:
	case SVC_TerminateTask:
		//Update Sch Table, Ready Queue
		MYRTOS_Update_Scheduler_Table();
		//OS is in Running State
		if(OS_Control.OSmodeID == OSrunning)
		{
			if(strcmp(OS_Control.CurrentTask->TaskName, "idleTask") !=0)
			{
				//Decide what Next
				Decide_whatNext();
				//Trigger OS_PendSV (switch context/restore)
				Trigger_OS_PendSV();
			}
		}
		break;
	case SVC_TaskWaitingTime:
		MYRTOS_Update_Scheduler_Table();
		break;

	}

}

//Thread Mode
void MYRTOS_OS_SVC_Set(SVC_ID id)
{
	switch (id)
	{
	case SVC_ActivateTask:
		__asm("svc #0x00");
		break;
	case SVC_TerminateTask:
		__asm("svc #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm("svc #0x02");
		break;
	}

}

void MYRTOS_ActivateTask(Task_ref* Tref)
{
	Tref->TaskState = Waiting;
	MYRTOS_OS_SVC_Set(SVC_ActivateTask);

}
void MYRTOS_TerminateTask(Task_ref* Tref)
{
	Tref->TaskState = Suspend;
	MYRTOS_OS_SVC_Set(SVC_TerminateTask);
}

void MYRTOS_TaskWait(unsigned int NoTicks, Task_ref* SelfTref)
{
	SelfTref->TimeWaiting.Blocking = enable;
	SelfTref->TimeWaiting.Ticks_Count = NoTicks;
	//Task should be blocked
	SelfTref->TaskState = Suspend;
	// to be suspended immediately
	MYRTOS_OS_SVC_Set(SVC_TerminateTask);


}


void MYRTOS_StartOS()
{
	OS_Control.OSmodeID = OSrunning;
	//set default "Current Task = Idle Task"
	OS_Control.CurrentTask = &MYRTOS_idleTask;
	//Activate Idle Task
	MYRTOS_ActivateTask(&MYRTOS_idleTask);
	//Start Ticker
	Start_Ticker(); // 1ms

	OS_Set_PSP(OS_Control.CurrentTask->Current_PSP);
	// Switch Thread mode from MSP to PSP (Unprivileged)
	OS_Switch_SP_to_PSP;
	OS_Switch_UnPrivileged;
	MYRTOS_idleTask.p_TaskEntry();
}

void MYRTOS_Update_TaskWaitingTime()
{
	for(int i=0; i< OS_Control.NoOfActiveTasks ; i++)
	{
		if(OS_Control.OSTasks[i]->TaskState == Suspend) // its blocking untill meet the timeline
		{
			if(OS_Control.OSTasks[i]->TimeWaiting.Blocking == enable)
			{
				OS_Control.OSTasks[i]->TimeWaiting.Ticks_Count--;
				if(OS_Control.OSTasks[i]->TimeWaiting.Ticks_Count == 0)
				{
					OS_Control.OSTasks[i]->TimeWaiting.Blocking = disable;
					OS_Control.OSTasks[i]->TaskState = Waiting;
					MYRTOS_OS_SVC_Set(SVC_TaskWaitingTime);
				}
			}
		}
	}

}





