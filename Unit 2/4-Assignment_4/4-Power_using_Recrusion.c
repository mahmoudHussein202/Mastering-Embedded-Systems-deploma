/*
 * Power_using_Recrusion.c
 *
 *  Created on: Aug 4, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
int Positive_Power(int base, int power );
int main ()
{
	int base,power;
	printf("enter base number :  \n " );
	fflush(stdout);fflush(stdin);
	scanf("%d",&base);
	printf("enter power number (Positive integer)");
	fflush(stdout);fflush(stdin);
	scanf("%d",&power);
	// make sure that power is positive
	while (power < 0)
	{
		printf("Wrong, Enter a positive power");
		scanf("%d",&power);
	}
		printf("%d ^ %d = %d ",base,power,Positive_Power(base,power));



	return 0;
}

int Positive_Power(int base,int power)
{
	if (power!=0)
	return base*Positive_Power(base,power-1);

	return 1;
}
