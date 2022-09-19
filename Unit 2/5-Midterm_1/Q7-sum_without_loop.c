/*
 * sum_without_loop.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
int sum_without_loop(int num);
int main ()
{
	int num;
	printf("enter an integer : " );
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	printf("sum from 1 to %d  = %d ",num,sum_without_loop(num));
	return 0;
}

int sum_without_loop(int num)
{
	int sum=0,i=0;
	begin:
	i++;
	sum=sum+i;

	if (i<100)
		goto begin;

	return sum;

}
