#include <stdio.h>
void main()
{
    int n,i,sum;
    printf("enter an integer :  " );
    scanf("%d",&n);
    
    for (i=1; i<=n;i++){
        
        sum=sum+i;
    }
    printf("sum = %d",sum);
    
}