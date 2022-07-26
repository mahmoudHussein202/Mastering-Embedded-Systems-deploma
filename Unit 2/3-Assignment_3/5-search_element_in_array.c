/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "stdlib.h"

int main () {
    int n,i,s;
    printf("enter number of elements :  ");
    scanf("%d",&n);
    
    int *ptr;
    ptr= (int*)malloc(sizeof(int)*n);
    
    
    
    
    for (i=0;i<n;i++)
    {
        ptr[i]=(i+1)*10+(i+1);
    }
    for (i=0;i<n;i++)
    {
        printf("%d \t",ptr[i]);
    }
    
    printf("\n enter the element to be searched : ");
    scanf("%d",&s);
    
    for (i=0;i<n;i++){
        
        if (ptr[i]==s){
            printf("number found at location : %d",i+1);
            break;
        }
        
    }
    
   

	return 0;

}
