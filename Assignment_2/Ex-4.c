#include <stdio.h>
void main()
{
    float n;
    printf("enter an number :  " );
    scanf("%f",&n);
    
    n>0?printf("%f in positive",n):(n<0?printf("%f is negative",n):printf("%f is zero",n));
  
    
    
}