/*
 * Quiz--Reverse_input_array.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 */


#include "stdio.h"
#include <stdlib.h>
void Reverse_array(int* arr, int size);
int main()
{
	int *arr,size,i=0,element=0;
	printf("enter size of array : ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&size);
	arr= (int*)malloc(size*sizeof(int));
	// getting array elements

	printf("enter array elements :");
	fflush(stdout),fflush(stdin);
	while (i<=size-1)
	{
		scanf("%d",&element);
		arr[i]=element;
		i++;
	}

	printf("Reverse :");
	Reverse_array(arr,size);


	return 0;
}

void Reverse_array(int* arr, int size)
{
	if (size!=0)
	{
	printf("%d",arr[size-1]);
	Reverse_array(arr,size-1);
	}
}
