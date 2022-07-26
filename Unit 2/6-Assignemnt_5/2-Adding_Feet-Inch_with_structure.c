/*
 * Adding_Feet-Inch_with_structure.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"

struct Sfeet_inch
{
	float feet;
	float inch;
} FInum_1,FInum_2,FIsum;

int main()
{
	int feetCounter=0;

	printf("enter information of first distance : \n");
	printf("enter feet : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&FInum_1.feet);
	printf("enter inches : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&FInum_1.inch);

	printf("enter information of second distance : \n");
	printf("enter feet : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&FInum_2.feet);
	printf("enter inches : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&FInum_2.inch);

	FIsum.inch=FInum_1.inch+FInum_2.inch;
	while (FIsum.inch >= 12)
	{
		FIsum.inch=FIsum.inch-12;
		feetCounter++;
	}
	FIsum.feet=FInum_1.feet+FInum_2.feet+feetCounter;

	printf("\nsum of distances = %.0f ' %.2f \" ",FIsum.feet,FIsum.inch);



	return 0;
}

