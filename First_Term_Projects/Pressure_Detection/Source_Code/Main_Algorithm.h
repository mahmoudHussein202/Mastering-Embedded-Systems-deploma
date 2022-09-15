#include "stdint.h"
typedef enum {
    recieving_state,
    alarm_on_state,
    alarm_off_state
} Main_Algorithm_state_id;

void (*Main_Algo_state_pointer)();
void Main_Algo_init_F();
Main_Algorithm_state_id Algo_alarm_off_F();
Main_Algorithm_state_id Algo_alarm_on_F();