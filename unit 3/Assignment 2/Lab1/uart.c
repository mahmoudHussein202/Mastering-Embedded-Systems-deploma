#define  uart0  *((volatile unsigned int *) ((unsigned int*)0x101f1000))
#include "uart.h"
void UART_send_string (char* ptr)
{
	while (*ptr !=0 )
	{
		uart0= *ptr;
		ptr++;
	}

}