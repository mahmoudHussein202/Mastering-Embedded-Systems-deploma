#include "stdint.h"
#include "RCC.h"
#include "GPIO.h"
void main()
{
    //enable portA clock
    RCC_GPIOB_ENB();
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    while (1)
    {
        GPIOA_ODR |= 1<<13;
        for (int i = 0 ; i < 5000 ; i++);
        GPIOA_ODR &= ~(1<<13);
        for (int i = 0 ; i < 5000 ; i++);
    }
}
