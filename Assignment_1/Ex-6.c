#include <stdio.h>

void main()
{
    float a,b,temp;
  printf("enter value of a :  ");
  scanf("%f",&a);
  printf("enter value of b :  ");
  scanf("%f",&b);
  temp=a;
 a=b;
 b=temp;
 
 printf("after swaping, value of a : %f \n after swaping , value of b :%f \n",a,b);
  

    
}