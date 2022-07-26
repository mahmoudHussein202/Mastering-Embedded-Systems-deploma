/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Mahmoud Hussein
 */

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#define max 100

int main () {
    char a[max],b;
    int i,counter=0;

    printf("enter a string : ");
    
    fgets(a,max,stdin);

    
    
   printf("\n enter a character to find its frequency  : ");
    scanf("%c",&b);
    
    for (i=0;i<(unsigned int)strlen(a)-1;i++){
        if (a[i]==b){
            counter=counter+1;
        }
    }
    
    printf("freqency of %c = %d ",b,counter);
    
   

	return 0;

}
