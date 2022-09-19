/*
 * Reverse_array_element.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mahmoud Hussein
 */
#include "stdio.h"
void reversed_array(int* arr,int size);
int main () {
	int arr[5]={1,2,3,4,5},i;
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("input: ");
	for (i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	reversed_array(arr,size);
	printf("\nreversed: ");
	for (i=0;i<size;i++)
		{
			printf("%d ",arr[i]);
		}

	return 0;
}

void reversed_array(int* arr,int size)
{
	int temp,i=0,limit;
	if(size%2!=0)
	{
		limit = (size+1)/2;
	}
	else
	{
		limit=size/2;
	}
	for(i=0;i<limit;i++)
	{
		temp=arr[i];
		arr[i]=arr[size-1-i];
		arr[size-1-i]=temp;
	}


}
