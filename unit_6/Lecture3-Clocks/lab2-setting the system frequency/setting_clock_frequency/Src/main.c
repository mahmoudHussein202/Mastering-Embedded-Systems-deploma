#include "stdint.h"
#include "RCC.h"
#include "GPIO.h"
int main()
{
	//RCC_INIT
	/* ********************Note*************************:
	 * PLL Must be Configured First before Enabling it
	 * once a clk source is selected, you can't configure it.
	 * ***********************************************/
	RCC_PLLMUX_by_8();
	RCC_Enable_PLL();
	RCC_select_PLL();
	RCC_APB1_prescalar_by_2();
	RCC_APB2_prescalar_by_2();
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
    return 0;
}
