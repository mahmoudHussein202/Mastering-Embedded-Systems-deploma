/*
 * main.c
 *
 *  Created on: Jul 30, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "string.h"
int main () {
	char a[100];
	char b[100];
	int i;
	printf("enter the string :  ");
	fflush(stdin);fflush(stdout);
	gets(a);

	for (i=0; i<strlen(a); i++)
	{
		b[strlen(a)-1-i]=a[i];

		if (i== strlen(a)-1)
		{
			b[strlen(a)]=0;
		}
	}

	printf("%s",b);

	return 0;
}

