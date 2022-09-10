#include "stdint.h"
#include "DC.h"
#include "stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin)) 

uint32_t DC_speed ;

void motor_init()
{
    DC_speed = 0 ;
    motor_state_pointer = motor_set_speed;
}


void motor_set_speed()
{
    motor_state_pointer = motor_set_speed;
    print("\n ---     Motor_set_speed_state :  speed = %d",DC_speed);
    print("\n--------------------------------------------------------------");
}
