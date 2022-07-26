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
	int st_num;  /*student numbers*/
	int i; /*for loop*/
	struct Sstudent class [100];
	struct Sstudent element;
	printf("enter number of students : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&st_num);

	/*storing*/

	for (i=0; i<st_num;i++)
	{
		printf("enter information of student no.%d \n -------------------------------------\n\n",i+1 );
		fflush(stdout);fflush(stdin);
		printf("1- Student no.%d name :",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%s",element.name);

		printf("2- Student no.%d roll :",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%d",&element.roll);

		printf("3- Student no.%d marks :",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%f",&element.marks);

		class[i]=element;
		printf("\n\n");
	}

	/*displaying data */

	int n=0;
	char flag;
	printf("data stored successfully, do you want to display a certain data ? type (y,n) \n");
	fflush(stdout);fflush(stdin);
	scanf("%c",&flag);
	if (flag=='y')
	{
		printf("enter number of student ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&n);
		student_print(class[n-1]);

	}




	return 0;
}


void student_print (struct Sstudent element)
{
	printf("student information : \n1-name : %s \n2-roll : %d\n3-marks : %f\n",element.name,element.roll,element.marks);
}
