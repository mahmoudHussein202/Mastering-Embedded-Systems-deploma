/*
 * Quiz--index_of_last_occurence_in_array.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 */


#include "stdio.h"
#include <stdlib.h>
int last_occurence(int* arr, int size,int element);
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

	printf("what is the value you want to check the last occurrence of it ? ");
	fflush(stdout),fflush(stdin);
	scanf("%d",&element);

	printf("last occurrence index = %d",last_occurence(arr,size,element));




}


int last_occurence(int* arr, int size,int element)
{
	int i;
	for (i=size-1;i>0;i--)
	{
		if (arr[i]==element)
		{
			return i;
			break;
		}
		else if(i==0)
		{
			return (int)NULL;
		}
	}
	return 0;

}
