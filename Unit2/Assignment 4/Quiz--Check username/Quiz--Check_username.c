/*
 * Prime_number_between_two_intervals.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Mahmoud Hussein
 */
 
#include "stdio.h"
#include "string.h"
int main() {
	char username[]="USERNAME",store[100];

	printf("enter your username \n");
	fflush(stdout);fflush(stdin);
	scanf("%s",store);
	if(stricmp(username,store))
	{
		printf("username is not correct");

	}
	else

	printf("username is correct");


	return 0;
}
