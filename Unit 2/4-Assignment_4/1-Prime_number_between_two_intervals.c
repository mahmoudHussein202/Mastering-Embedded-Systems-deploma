/*
 * Prime_number_between_two_intervals.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Mahmoud Hussein
 */
#include "stdio.h"
void primeNumber(int x , int y);
int main() {
	int x,y;
	printf("enter two numbers : \n");
	fflush(stdin),fflush(stdout);
	scanf("%d%d",&x,&y);
	primeNumber(x,y);
	return 0;

}

void primeNumber(int x , int y)
{
	int checker=x+1,i;

	for (;checker<y;checker++)
	{

		for (i=2;i<checker;i++)
		{
			if (checker%i==0)
			{
				break;
			}
			else if (i==checker-1)
			{
				printf("%d ",checker);
			}

		}


	}
}








