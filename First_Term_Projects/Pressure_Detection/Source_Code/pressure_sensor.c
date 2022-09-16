#include "pressure_sensor.h"
#include "driver.h"
sensor_state_id_t sensor_state;
int pressure_value;
extern int pressure_recevied;

void sensor_init_F()
{
    pressure_value = 0 ; 
    sensor_state_pointer = send_reading_F;
}
void send_reading_F()
{
    sensor_state = reading_state;
    pressure_value = getPressureVal();
    pressure_recevied = pressure_value;
    sensor_state_pointer = send_reading_F;
}