/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int x;
void globaltest(int*p1,int*p2);


int main()
{

	char *ptr="article";

	printf("%s",ptr);

	return 0;

}

void f(char** p)
{
	char *t;
	t=(p);
	printf("%s",t);
}

