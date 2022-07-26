/*
 * 1-store_information_using_structure.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include <conio.h>

struct Sstudent
{
	char name[100];
	int roll;
	float marks;
};

void student_print (struct Sstudent element);

int main()
{
	struct Sstudent student_1;
	printf("enter information of students : \nenter name : ");
	fflush(stdout);fflush(stdin);
	scanf("%s",student_1.name);
	printf("enter roll number : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&student_1.roll);
	printf("enter marks :");
	fflush(stdout);fflush(stdin);
	scanf("%f",&student_1.marks);

	student_print(student_1);


	return 0;
}


void student_print (struct Sstudent element)
{
	printf("student information : \n1-name : %s \n2-roll : %d\n3-marks : %f\n",element.name,element.roll,element.marks);
}
