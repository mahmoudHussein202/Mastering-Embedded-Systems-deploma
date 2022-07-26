/*
 * Reverse_using_recrusion.c
 *
 *  Created on: Aug 4, 2021
 *      Author: Mahmoud Hussein
 *
 */

#include "stdio.h"
#include "string.h"
#define max 100
void Reverse (char* arr, int x);

int main () {
	char arr[max];
	int size;
	printf("enter a sentence : \n");
	fflush(stdout);fflush(stdin);
	fgets(arr,max,stdin);
	size= strlen(arr);
	Reverse(arr,size);





	return 0;
}

void Reverse (char* arr, int x)
{
	if (x==0)
		return ;
	else
	{
	printf("%c",arr[x-1]);
	Reverse(arr,x-1);
	}

}
