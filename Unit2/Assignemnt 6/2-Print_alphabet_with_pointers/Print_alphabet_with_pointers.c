/*
 * Print_alphabet_with_pointers.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Mahomud Hussein
 */

#include "stdio.h"
int main()
{
	int a=65,i;
	char arr[26]; /*store alphabet in an array*/

	for (i=0;i<sizeof(arr);i++)
	{
		arr[i]=a+i;
	}

	char* ptr=arr;
	for(i=0;i<sizeof(arr);i++)
	{
		printf("%c  ",ptr[i]);
	}

	return 0;
}

