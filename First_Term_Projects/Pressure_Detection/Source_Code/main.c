#include "driver.h"
extern void sensor_init_F();
extern void Main_Algo_init_F();
extern void Alarm_init();
extern void (*Alarm_controler_state_pointer)();
extern void (*sensor_state_pointer)();
extern void (*Main_Algo_state_pointer)();

void setup ()
{
    GPIO_INITIALIZATION();
    sensor_init_F();
    Main_Algo_init_F();
    Alarm_init();
}

int main()
{
    setup();
    while(1)
    {
        sensor_state_pointer();
        Delay(1000);
        Main_Algo_state_pointer();
        Alarm_controler_state_pointer();
    }
    return 0 ;
}