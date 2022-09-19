/*
 * Q1-sum_all_digits_of_num.c
 *
 *  Created on: Aug 11, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "math.h"
float squroot(float num);
int main() {
	float num;
	printf("enter the number :");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num);
	printf("square root = %.3f",squroot(num));
	return 0;

}

float squroot(float num){

	float sqr=pow(num,0.5);
	return sqr;
}
