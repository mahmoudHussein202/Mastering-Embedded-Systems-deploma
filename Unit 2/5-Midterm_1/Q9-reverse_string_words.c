/*
 * 9-reverse_string_words.c
 *
 *  Created on: Aug 12, 2021
 *      Author: mahmo
 */
#include "stdio.h"
#include "string.h"
void reverse_string(char* str,int size);
int main ()
{
	char str[]="mohamed gamal";
	int size=sizeof(str);

	printf("%s",str);
	fflush(stdout);fflush(stdin);
	reverse_string(str,size);

	printf("\n%s",str);


}


void reverse_string(char* str,int size)
{
	int index=size-1,i,j=0;
	char arr[100];
	while (index >-1)
	{
		while (str[index]!=32)
		{
			if(index==-1)
				break;
			index--;

		}
		for (i=index+1;1;i++)
		{
			if (str[i]==32 || str[i]==0)
				break;
			arr[j]=str[i];
			j++;

		}
		arr[j]=32;
		j++;
		index--;
	}
	arr[size]='\0';

	strcpy(str,arr);
}

