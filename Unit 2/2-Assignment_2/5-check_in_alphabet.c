/*
 * main.c
 *
 *  Created on: Jul 25, 2021
 *      Author: mahmoud
 */


#include <stdio.h>
#include"stdbool.h"

void main()
{
    int i;
    int j;
    char a;
    bool checker=false ;
printf("Enter a character : \n");
scanf("%c",&a);

for (i=65;i<=90;i++)
{
    if (i==a){
        printf("%c is an alphabet",a );
        checker=true;
        break;
    }
    
}

for (i=97;i<=122;i++)
{
    if (i==a){
        printf("%c is an alphabet",a );
        checker=true;
        break;
    }
    
}

if (checker==false)
{
    printf("%c is not an alphabet",a);
}
    
}


