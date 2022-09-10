#include "stdint.h"
typedef enum {
    waiting_state_e,
    driving_state_e
}Algo_state_t;

 /*---- init ------*/
 void Algo_init();

/*pointer to Algo_states*/
void(*Algo_state_pointer)();

/*---- signals ----*/
void Algo_recieve_distance();
void Algo_send_speed();

/* states */
void waiting_state();
void driving_state();

