/*
 * power_three_check.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 *
 */
#include "stdio.h"
int power_three_Checker(int x);
int main ()
{
	int n;
	printf("Enter the number :") ;
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("%d ------> %d",n,power_three_Checker(n));





	return 0;
}

int power_three_Checker(int x)
{

	while (x%3==0)
	{
		x/=3;
	}
	if (x==1)
		return 0;
	else
		return 1;
}
