#include <stdio.h>
void main()
{
    int n,i,product=1;
    printf("enter an integer :  " );
    scanf("%d",&n);
    if (n<0){
        printf("error, factorial of negative doesn't exist");
        
    }
    else
    {
    for (i=n;i>=1;i--)
    {
     product=product*i;
    }
    printf("factorial = : %d",product);
    }
    
}