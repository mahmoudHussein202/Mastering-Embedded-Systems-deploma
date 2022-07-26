/*
 * 5-passing_argument_to_macros.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mahmoud Hussein
 */
#include "stdio.h"
#define pi 3.14

#define area(r)(pi*r*r)
int main ()
{
	float radius,area;
	printf("enter radius : " );
	fflush(stdout);fflush(stdin);
	scanf("%f",&radius);

	area=area(radius);
	printf("area = %.2f ",area);

	return 0;
}

