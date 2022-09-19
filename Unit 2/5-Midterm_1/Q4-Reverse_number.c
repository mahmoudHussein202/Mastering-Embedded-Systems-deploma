/*
 * Reverse_number.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mahmoud Hussein
 *
 */

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
int reverse(char* num,int size);

int main()
{
	char num[100];
	int size;
	printf("enter an integer : ");
	fflush(stdout);fflush(stdin);
	scanf("%s",num);
	size=strlen(num);



	printf("reverse =  %d",reverse(num,size));

	return 0;
}

int reverse(char* num,int size)
{
	char arr[size];
	int i,reverse_num;
	for (i=0;i<size;i++)
	{
		arr[i]=num[size-1-i];
	}

	reverse_num=(int)atoi(arr);

	return reverse_num;
}
