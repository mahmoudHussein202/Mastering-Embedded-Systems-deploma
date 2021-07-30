/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "stdlib.h"

int main () {
    int rows,columns,i,j;
    printf("enter rows and columns of matrix  \n ");
    scanf("%d%d",&rows,&columns);
    
    int **array ;
    array= (int**)malloc(sizeof(int*)*rows);
    
    for (i=0;i<rows;i++){
        array[i]= (int*)malloc(sizeof(int)*columns);
    }
    
    printf("enter elemnets of matrix : \n ");
    
    for (i=0;i<rows;i++) 
    {
        for (j=0;j<columns;j++)
        {
            printf("element %d%d = ",i,j);
            scanf("%d",&array[i][j]);
            
        }
    }
     printf("the matrix =  \n");
     for (i=0;i<rows;i++) 
    {
        for (j=0;j<columns;j++)
        {
            printf("%d \t",*(&array[i][j]));
           
            
        }
        printf("\n");
    }
    
    printf("transpose of matrix =  \n");
     for (i=0;i<columns;i++) 
    {
        for (j=0;j<rows;j++)
        {
            printf("%d \t",*(&array[j][i]));
           
            
        }
        printf("\n");
    }
 

	return 0;

}
