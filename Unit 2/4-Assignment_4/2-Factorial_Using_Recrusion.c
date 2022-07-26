/*
 * Factorial_Using_Recrusion.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
int factorial(int x);


int main()
{
	int n;
	printf("enter a positive integer ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	printf("factorial of %d  =  %d ",n,factorial(n));



	return 0;
}




int factorial(int x)
{
	if (x==1) {

		return x;
	}
	else {
		return x*factorial(x-1);

	}

}
