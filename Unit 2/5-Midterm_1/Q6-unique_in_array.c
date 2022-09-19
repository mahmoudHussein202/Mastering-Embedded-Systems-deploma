/*
 * 6-unique_in_array.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mahmoud Hussein
 */
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
int unique_num(int* arr,int size);
int main ()
{
	int arr[100],size,element,i;
	printf("enter size of array : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&size);
	printf("enter array elements : ");
	fflush(stdout);fflush(stdin);

	for (i=0;i<size;i++)
	{
		scanf("%d",&element);
		arr[i]=element;
	}

	printf("unique number is : %d",unique_num(arr,size));
	return 0;
}
int unique_num(int* arr,int size)
{
	int i,j,counter=0;
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			if (arr[i]==arr[j])
				counter++;
		}
		if (counter>1)
		{
			counter=0;
			continue;
		}
		else if (counter==1)
		{
			return arr[i];
		}

	}
	return 0;
}
