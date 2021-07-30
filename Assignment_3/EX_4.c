/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Mahmoud Hussein
 */

#include "stdio.h"
#include "stdlib.h"

int main () {
    int n,a,l,i;
    int *ptr;
    
   printf("enter number of elements : \n"); 
   scanf("%d",&n);
   ptr = (int*)malloc(n*sizeof(int));
   
 
  for (i=0;i<n;i++){
      *(ptr+i)=i+1;
  }
   
  for (i=0;i<n;i++) {
      printf("%d",ptr[i]);
  }
   
   
   
  printf("\n enter element to be insert : \n"); 
  scanf("%d",&a);
  printf("enter the location : \n"); 
  scanf("%d",&l);
  
  ptr = (int*)realloc(ptr,sizeof(int)*(n+1));
  
  for (i=n-1;i>=l-1;i--)
  { 
      ptr[i+1]=ptr[i];
      
  }
  ptr[l-1]=a;
   
    for (i=0;i<n+1;i++) {
      printf("%d",ptr[i]);
  }
  
   
   

	return 0;

}
