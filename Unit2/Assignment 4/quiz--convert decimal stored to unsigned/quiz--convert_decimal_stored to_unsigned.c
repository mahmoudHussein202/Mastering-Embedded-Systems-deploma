/*
 * quiz--convert_decimal_stored to_unsigned.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
int Hexa_convert(int num);

int main () {
	int num=0;
	int ASCII_arr[10]={0x30,0x40,0x50,0x60,0x70,0x80,0x90};
	printf("enter Hexadecimal from 30 to 90");
	scanf("%x",&num);
	Hexa_convert(num);



	return 0;
}

int Hexa_convert(int num)
{
	printf("%c",num);
return num;
}
