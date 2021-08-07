/*
 * Quiz--index_of_last_occurence_in_array.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 */
#include "stdio.h"

int forth_element(int num);
int main ()

{
	/* variables */
	int num=0;

	/*action */
	printf("enter the number :  ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);

	fflush(stdout);fflush(stdin);
	printf("forth element = %d",forth_element(num));






	return 0;
}


int forth_element(int num)
{
	char arr[32];
	int r,i=0;

	while (num!=0)
	{
		num=num/2;
		r=num%2;
		arr[i]=r;
		i++;

	}
if (arr[3]==0)
	return 0;
else
	return 1;
}
