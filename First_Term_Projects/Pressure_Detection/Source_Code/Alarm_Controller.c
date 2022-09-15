#include "stdint.h"
#include "Alarm_Controller.h"
#include "driver.h"
uint8_t Alarm_Condition;
Alarm_Controller_STATE_t Alarm_Controller_state;
void Alarm_init()
{
    Alarm_Condition = 0;
    Alarm_controler_state_pointer = set_alarm_off_F;
}

Alarm_Controller_STATE_t set_alarm_on_F()
{
    Alarm_Controller_state = Alarm_on_state;
    Set_Alarm_actuator(1);
    (Alarm_Condition > 0 )? (Alarm_controler_state_pointer = set_alarm_on_F):(Alarm_controler_state_pointer = set_alarm_off_F);
    
}
Alarm_Controller_STATE_t set_alarm_off_F()
{
    Alarm_Controller_state = Alarm_off_state;
    Set_Alarm_actuator(0);
    (Alarm_Condition > 0 )? (Alarm_controler_state_pointer = set_alarm_on_F):(Alarm_controler_state_pointer = set_alarm_off_F);
}

