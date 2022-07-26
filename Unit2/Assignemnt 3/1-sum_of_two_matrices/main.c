#include "stdio.h"
#include "string.h"
int main() {
	char s[100];
	char temp;
	printf("enter a string ");
	fflush(stdout);fflush(stdin);
	gets(s);
	int size=strlen(s);
	int i;
	int limit =size;

	if (size%2!=0)
	limit++;

	for(i=0;i<size/2;i++)
	{
	temp=s[i];
	s[i]=s[size-1-i];
	s[size-1-i]=temp;
	}

	printf("after reverse : %s \n",s);
	return 0;
}
