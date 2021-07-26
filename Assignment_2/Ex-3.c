#include <stdio.h>

void main()
{
    float a,b,c,max;
printf("Enter three numbers : \n");
scanf("%f%f%f",&a,&b,&c);

max=a>b?a:b;
max=max>c?max:c;
printf("largest number : %f",max);

    
}