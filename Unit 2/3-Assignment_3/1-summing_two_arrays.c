/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: mahmoud
 */

#include "stdio.h"

int main () {
	float a[2][2] , b[2][2] , c[2][2];
	int i,j;
	printf("enter elements of first matrix \n");

	for (i=1;i<=2;i++)
	{
		for (j=1;j<=2;j++)
		{
			printf("array of a%d%d ",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%f",&a[i][j]);

		}

	}
	printf("enter elements of second matrix \n");

	for (i=1;i<=2;i++)
	{
		for (j=1;j<=2;j++)
		{
			printf("array of b%d%d ",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%f",&b[i][j]);
		}

	}

	printf("sum of matrix : \n");

	for (i=1;i<=2;i++)
	{
		for (j=1;j<=2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("%f \t",c[i][j]);
		}
		printf("\n");

	}



	return 0;

}
