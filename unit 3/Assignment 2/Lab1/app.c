#include "uart.h"
unsigned char string [100]= "Learn-in-depth-Hussein";
void main (void) 
{


UART_send_string(string);

}