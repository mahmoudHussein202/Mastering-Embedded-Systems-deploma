/*
 * main.c
 *
 *  Created on: Jul 25, 2021
 *      Author: mahmoud
 */


#include <stdio.h>

void main()
{
    char letter;
printf("Enter an alphabet  : ");
scanf("%c",&letter);

switch (letter) 
{
    case 'i':
    case 'e':
    case 'o':
    case 'a':
    case 'u':
    case 'I':
    case 'E':
    case 'O':
    case 'A':
    case 'U':
    {
        printf("%c is vowel",letter);
        break;
    }
    
    default : 
    {
        printf("%c is consonant",letter);
        break;
    }
    
}
  

    
}
    



