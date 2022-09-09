#ifndef _CA_H_
#define _CA_H_
#include "stdio.h"
#include "stdint.h"
typedef enum
{
    waiting_state,
    driving_state,
}state_id_t;

state_id_t current_state;
void (*state_pointer)();
void waiting_state_F();
void driving_state_F();
int random_distance_F(int l , int r , int count);

#endif

