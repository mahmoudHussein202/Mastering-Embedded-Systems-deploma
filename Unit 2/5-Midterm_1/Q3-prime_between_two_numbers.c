/*
 * prime_between_two_numbers.c
 *
 *  Created on: Aug 11, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
void print_prime(int n1,int n2);

int main() {
	int n1,n2;
	printf("enter 1st number :");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n1);
	printf("enter 2nd number :");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n2);

	print_prime(n1,n2);
	return 0;

}

void print_prime(int n1,int n2)
{
	int i,j,a,b;
	if (n1>=n2)
	{
		a=n1; b=n2;
	}
	else
	{
		a=n2; b=n1;
	}

	for (i=b;i<=a;i++)
	{
		if (i==1)
		{
			printf("%d ",i);
			continue;
		}
		for(j=2;j<i;j++)
		{
			if (i%j==0)
				break;

		}
		if (j==i)
		printf("%d ",i);
	}

}
