/*
 * pointer_demonstration.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Mahmoud Hussein
 */


#include "stdio.h"

int main()
{
	int m;
	m=29;
	printf("Address of m : %x \nValue of m: %d\n",(unsigned int)&m,m);

	int *ab=&m;
	printf("------------------------------------------\nNow ab is assigned with the address of m.\n");
	printf("\nAddress of pointer ab : %x \nContent of poiner ab : %d\n",(unsigned int)ab,*ab);
	m=34;
	printf("-------------------------------------------\nThe value of m assigned to 34 now.\n");
	printf("\nAddress of pointer ab : %x \nContent of poiner ab : %d\n",(unsigned int)ab,*ab);
	*ab=7;
	printf("--------------------------------------------\nThe pointer variable ab is assigned with thevalue 7 now.\n");
	printf("\nAddress of m : %x \nValue of m: %d\n",(unsigned int)&m,m);


	return 0;
}
