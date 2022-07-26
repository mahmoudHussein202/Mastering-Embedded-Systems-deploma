/*
 * 5-pointer_act_with_struct.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include <string.h>
struct Semployee
{
	char name[50];
	int id;

};
int main ()
{int i;
	struct Semployee employees[50];
	struct Semployee* ptr[50];  /*array of pointers with struct type*/

	for (i=0;i<50;i++)
	{
		ptr[i]=&employees[i];
	}


	/*filling one element, for example : filling employee[0] , fill it with pointer*/
	strcpy(ptr[0]->name,"alex");
	ptr[0] ->id=1002;

	struct Semployee** Parr=&(ptr[0]);

	printf("Employee name : %s  \nID: %d", (*Parr)->name,(*Parr)->id );









	return 0;
}
