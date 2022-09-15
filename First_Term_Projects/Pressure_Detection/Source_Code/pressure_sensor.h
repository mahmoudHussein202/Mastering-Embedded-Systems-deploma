#ifndef _PRESSURE_SENSOR_H_
#define _PRESSURE_SENSOR_H_
#include "stdint.h"
typedef enum {
    reading_state
}sensor_state_id_t;
void (*sensor_state_pointer)();
void sensor_init_F();
sensor_state_id_t send_reading_F();
#endif