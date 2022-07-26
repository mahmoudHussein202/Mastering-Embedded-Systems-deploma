/*
 * Quiz_test.c
 *
 *  Created on: Aug 16, 2021
 *      Author: mahmo
 */

#include "stdio.h"
#define cube(x) x*x*x

int main()
{
	int a,b=3;
	a=cube(b++);
	printf("%d %d",a,b);


	return 0;
}
