/*
 * Quiz--swapping_two_arrays.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "stdlib.h"
void swap(int* A,int sizeA , int*B, int sizeB);
void print_array(int* arr);
int main() {

	int *A,s1;
	int *B,s2;
	int i,element;

	printf("enter size of array A :");
	fflush(stdout);fflush(stdin);
	scanf("%d",&s1);
	A= (int*)malloc(sizeof(int)*(s1+1));
	printf("enter elements of array A :\n");
	fflush(stdout);fflush(stdin);
	for (i=0;i<s1;i++)
	{
		scanf("%d",&element);
		A[i]=element;
	}
	A[s1]=987654;


	printf("enter size of array B :");
	fflush(stdout);fflush(stdin);
	fflush(stdout);fflush(stdin);
	scanf("%d",&s2);

	B= (int*)malloc(sizeof(int)*(s2+1));
	printf("enter elements of array B :\n");
	fflush(stdout);fflush(stdin);
	for (i=0;i<s2;i++)
	{
		scanf("%d",&element);
		B[i]=element;
	}
	B[s2]=987654;

	print_array(A);
	print_array(B);

	swap(A,(s1+1),B,(s2+1));

	print_array(A);
	print_array(B);




	return 0;
}
void swap(int* A,int sizeA, int*B,int sizeB)
{
	int* temp,i;


	temp= (int*)malloc(sizeA*sizeof(int));

	for (i=0;i<sizeA;i++)
	{
		temp[i]=A[i];
	}

	A= (int*)realloc(A,sizeB*sizeof(int));

	for (i=0;i<sizeB;i++)
		{
			A[i]=B[i];
		}
	B=(int*)realloc(B,sizeA*sizeof(int));

	for (i=0;i<sizeA;i++)
		{
			B[i]=temp[i];
		}
}

void print_array(int* arr){
	int i;
	for (i=0;arr[i]!=987654;i++){
		printf("%d \n",arr[i]);
	}
	printf("__________________________ \n");

}
