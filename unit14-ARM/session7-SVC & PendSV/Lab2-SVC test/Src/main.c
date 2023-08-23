/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng. Mahmoud Hussein
 * @brief          : using SVC, pass parameters and get a return value
 ******************************************************************************
 */
int OS_SVC_set(int a , int b, int SVC_ID);
int main(void)
{
	int results = OS_SVC_set(2, 8, 0);
    /* Loop forever */
	for(;;);
}
int OS_SVC_set(int a , int b, int SVC_ID)
{
	int return_value ;
	switch (SVC_ID)
	{
	case 0 :
		__asm("svc #0x00");
		break;
	case 1 :
		__asm("svc #0x01");
		break;
	case 2 :
		__asm("svc #0x02");
		break;
	}
	// r0 now have the return value
	__asm("mov %0, r0":
			"=r"(return_value) );
	return return_value;
}

__attribute ((naked)) void SVC_Handler()
{
	__asm("tst lr,#4    \n\t"
			"ITE EQ		\n\t"
			"mrseq r0,MSP	\n\t"
			"mrsne r0,PSP	\n\t"
			"B OS_SVC");
}

void OS_SVC(int* Stack_Frame)
{
	unsigned char SVC_number;
	unsigned int val1,val2;
	val1 = Stack_Frame[0];
	val2 = Stack_Frame[1];
	SVC_number = *((unsigned char*)(((unsigned char*)(Stack_Frame[6])-2)));
	switch (SVC_number)
	{
	case 0 :
		Stack_Frame[0] = val1 + val2;
		break;
	case 1 :
		Stack_Frame[0] = val1-val2;
		break;
	case 2 :
		Stack_Frame[0] = val1*val2;
		break;
	}
}
