/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "stdlib.h"

int main () {
	int i,n;
	float sum=0;
	printf("Enter number of data :   ");
	scanf("%d",&n);

	float *ptr;
	ptr =(float*)malloc(n*sizeof(float));

	for (i=0;i<n;i++)
	{
		printf("enter number %d: ",i+1);
		scanf("%f",ptr+i);

	}

	for (i=0;i<n;i++){
		sum=sum+*(ptr+i);

	}
	printf("average=  %.2f",sum/n);


	return 0;

}
