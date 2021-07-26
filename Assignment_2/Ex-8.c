#include <stdio.h>
void main()
{
    char op;
    float oper_1,oper_2,operation;
    printf("enter operator either + or - or / or * ");
    scanf("%c",&op);
    printf("enter the two operands ");
    scanf("%f%f",&oper_1,&oper_2);
    
    
    switch (op)
    {
        case'+':
        {
            operation = oper_1+oper_2;
            break;
        }
        case'-': 
        {
            operation= oper_1-oper_2;
            break;
        }
        case'*':
        {
            operation= oper_1*oper_2;
            break;
        }
        case'/':
        {
            operation=oper_1/oper_2;
            break;
        }
        
    }
    printf("%f %c %f = %f",oper_1,op,oper_2,operation);
}