/*
 * Quiz--index_of_last_occurence_in_array.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 */


#include "stdio.h"
#include <stdlib.h>
void last_occurence(int* arr, int size);
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

	last_occurence(arr,size);



}


void last_occurence(int* arr, int size)
{
	printf("the number is : %d \n The result : %d ",arr[size-1],size-1);
}
