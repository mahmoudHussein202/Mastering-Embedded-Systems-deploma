#include "stdint.h"
#include "Main_Algorithm.h"
#include "driver.h"
int pressure_recevied ;
int threshold ;
extern int Alarm_Condition;
Main_Algorithm_state_id Algo_state;

void Main_Algo_init_F()
{
    Main_Algo_state_pointer = Algo_alarm_off_F;
    threshold = 20;
}

void Algo_alarm_off_F()
{   
    Algo_state = alarm_off_state;
    Alarm_Condition = 0; // 0 is for alarm_off
    (pressure_recevied < threshold)? (Main_Algo_state_pointer = Algo_alarm_off_F):(Main_Algo_state_pointer = Algo_alarm_on_F);

}
void Algo_alarm_on_F()
{
    Algo_state = alarm_on_state;
    Alarm_Condition = 1 ;
    Delay(1000);
    (pressure_recevied < threshold)? (Main_Algo_state_pointer = Algo_alarm_off_F):(Main_Algo_state_pointer = Algo_alarm_on_F);
}