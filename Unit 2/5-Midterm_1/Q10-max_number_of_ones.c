/*
 * 10-max_number_of_ones.c
 *
 *  Created on: Aug 13, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
int max_ones(int num);
int main () {
	int num=110;
	printf("input = %d \n",num);
	printf("output = %d",max_ones(num));

	return 0;
}
int max_ones(int num)
{
	int remainder,i=0;
	int arr[100];


	while (num!=0)
	{
		remainder=num%2;
		num=num/2;
		arr[i]=remainder;
		i++;
	}

	int size=i;
	int counter=0,max=0;
	i=0;

	while(i<size)
	{
		if (arr[i]==0)
		{
			i++;
			while (arr[i]!=0 && i<size)
			{
				counter++;
				i++;
			}
			if (counter>max)
				max=counter;
			else
				counter=max;

			counter=0;
		}
		if (i==size-1)
			break;
	}

	return max;
}
