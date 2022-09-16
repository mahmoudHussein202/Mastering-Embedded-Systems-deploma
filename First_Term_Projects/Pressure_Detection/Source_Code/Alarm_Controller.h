#ifndef _ALARM_CONTROLLER_H_
#define _ALARM_CONTROLLER_H_
typedef enum {
    Alarm_on_state,
    Alarm_off_state
}Alarm_Controller_STATE_t;

void (*Alarm_controler_state_pointer)();
void Alarm_init();
void set_alarm_on_F();
void set_alarm_off_F();
#endif