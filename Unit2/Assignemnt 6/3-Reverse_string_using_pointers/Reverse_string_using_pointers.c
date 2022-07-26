/*
 * Reverse_string_using_pointers.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "string.h"

int main()
{
	char arr[100];
	printf("enter a string :");
	fflush(stdout);fflush(stdin);
	scanf("%s",arr);
	int i;
	char *ptr=arr;
	for (i=strlen(arr)-1;i>=0;i--)

	{
		printf("%c",*(ptr+i));
	}


	return 0;
}
