#include"Alarm_Controller.h"
#include "driver.h"
#include "Main_Algorithm.h"
#include "pressure_sensor.h"

int main()
{
    GPIO_INITIALIZATION();
    sensor_init_F();
    Main_Algo_init_F();
    Alarm_init();
    while(1)
    {
        sensor_state_pointer();
        Delay(20000);
        Main_Algo_state_pointer();
        Alarm_controler_state_pointer();
    }
}