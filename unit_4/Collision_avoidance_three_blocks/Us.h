#ifndef _Us_H_
#define _Us_H_
#include "stdint.h"
typedef enum {
    init_state_e,
    reading_state_e
} US_state_t;
void (*Us_state_pointer)();

/*init*/
void US_init();
//signal send 
void US_send_distance_F(uint32_t distance);
/* methods*/
uint32_t random_distance_F(int l , int r , int count);
void reading (uint32_t distance);
#endif