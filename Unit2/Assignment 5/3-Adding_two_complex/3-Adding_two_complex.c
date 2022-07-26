/*
 * 3-Adding_two_complex.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"

struct Scomplex
{
	float real ;
	float imaginary;
}n1,n2,sum;

struct Scomplex add (struct Scomplex n1 , struct Scomplex n2 );


int main()
{
	printf("for first complex number\nenter real and imaginary respectively: ");
	fflush(stdout);fflush(stdin);
	scanf("%f%f",&n1.real, &n1.imaginary);
	fflush(stdout);fflush(stdin);
	printf("for second complex number\nenter real and imaginary respectively :");
	fflush(stdout);fflush(stdin);
	scanf("%f%f",&n2.real, &n2.imaginary);

	sum=add(n1,n2);
	printf("sum= %0.2f + %0.2f i",sum.real,sum.imaginary);
	return 0;
}

struct Scomplex add (struct Scomplex n1 , struct Scomplex n2 )
{
	struct Scomplex sum;
	sum.real=n1.real+n2.real;
	sum.imaginary=n1.imaginary+n2.imaginary;

	return sum;
}
