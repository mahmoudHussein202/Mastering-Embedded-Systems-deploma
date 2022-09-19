/*
 * 5-number_of_ones_in_binary.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
int ones_in_binary(int num);
int main () {
	int num;
	printf("enter an integer : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	ones_in_binary(num);


	return 0;
}

int ones_in_binary(int num)
{
	char arr[100],remainder,ones_counter=0;
	int i,counter=0;
	int number=num;  /* for printing */

	while(num!=0)
	{
		remainder=num%2;
		num=num/2;
		arr[counter]=remainder;
		counter++;
	}
	for (i=0;i<counter;i++)
	{
		if (arr[i]==1)
			ones_counter++;
	}
	/* printing*/

	printf("binary of %d = ",number);
	for (i=counter-1;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
	printf(", so has %d ones ",ones_counter);



return ones_counter;
}
