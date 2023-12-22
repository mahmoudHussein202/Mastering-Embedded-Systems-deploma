#include "Interfaces\sw_interface.h"
#include "MCAL\GPIO.h"
#include "MCAL\WatchDog.h"
int main()
{   
    // GPIO INIT
    DDRA = 0xFF;
    DDRB = 0xFF;
    WD_set_TimeOut(WD_TimeOut_2_s);
    set_pin(PORTA,0);
    while(1)
    {
        set_pin(PORTA,0);
        WD_Enable();
        delay_us(10000);
        WD_Clear();
        toggle_pin(PORTA,0);
        delay_us(10000);
    }
    return 0;
}