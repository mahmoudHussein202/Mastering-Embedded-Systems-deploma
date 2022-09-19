/*
 * Q1-sum_all_digits_of_num.c
 *
 *  Created on: Aug 11, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "string.h"
int add_digits(char* arr,int size);

int main() {
	char num[100];
	int size;

	printf("enter a number :  ");
	fflush(stdout);fflush(stdin);
	scanf("%s",num);
	size=strlen(num);
	add_digits(num,size);



}

int add_digits(char* arr,int size)
{
	int sum=0,i;
	for (i=0;i<size;i++)
	{
		sum=sum+(arr[i]-48);
	}
	printf("%d",sum);

	return sum;
}
