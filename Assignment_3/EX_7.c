#include "stdio.h"
int main() {
	char s[100];
	int i,counter=0;

	printf("enter the string : ");
	fflush(stdout); fflush(stdin);

	gets(s);

	for (i=0;s[i]!=0;i++)
	{
		counter=counter+1;
	}

	printf("Length of string : %d",counter);



	return 0;
}
