#include <stdio.h>

void main()
{
    float a,b;
  printf("enter value of a :  ");
  scanf("%f",&a);
  printf("enter value of b :  ");
  scanf("%f",&b);
  
 a=a+b;
 b=a-b;
 a=a-b;
 
 printf("after swaping, value of a : %f \n after swaping , value of b :%f \n",a,b);
  

    
}