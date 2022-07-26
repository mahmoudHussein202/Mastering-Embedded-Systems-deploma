/*
 * 4-Reverse_array_element.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Mahmoud Hussein
 */
#include "stdio.h"
#include <stdlib.h>
int main()
{
	/*filling a dynamic array*/
	int n,i=0,temp;
	printf("input number of elements to store in the array (max 15) :  ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	while (n>15)
	{
		printf("Error- max number is 15 - try again");
		fflush(stdout);fflush(stdin);
		scanf("%d",&n);
	}

	int* ptr = (int*)malloc(sizeof(int)*n);
	printf("input %d number of element in the array \n",n);
	fflush(stdout);fflush(stdin);

	while (i<n)
	{
		printf("element of %d : ",i+1 );
		fflush(stdout);fflush(stdin);
		scanf("%d",ptr+i);
		i++;
	}

	/*make sure that n is even*/
	if (n%2!=0)
		n=n+1;

	/*swapping*/

	for(i=0;i<(n/2);i++)
	{
		temp=*(ptr+i);
		*(ptr+i)=*(ptr+(n-2-i));
		*(ptr+(n-2-i))=temp;

	}

	/*printing*/

	printf("\n------------------------------------\nafter Reversing : \n");
	for (i=0;i<(n-1);i++)
	{
		printf("element of %d : %d \n",i+1,*(ptr+i));
	}

	return 0;
}
