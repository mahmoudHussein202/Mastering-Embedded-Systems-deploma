#include "stdint.h"

typedef enum 
{
    motor_init_state,
    motor_set_speed   
} motor_status_t;


void (*motor_state_pointer)();

/* init */
void motor_init();

/*signal*/
void motor_recieve_speed();

/* states */ 
void motor_set_speed();


