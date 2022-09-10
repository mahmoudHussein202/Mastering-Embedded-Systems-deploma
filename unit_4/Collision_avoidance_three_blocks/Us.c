#include "stdint.h"
#include "Us.h"
#include "stdlib.h"
#include"stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin)) 

uint32_t US_distance; 
US_state_t US_state_id;
uint32_t random_distance_F(int l , int r , int count )
{
    int i ;
    for (i = 0 ; i < count; i++)
    {
        uint32_t rand_num = (rand()%(r-l+1))+l;
        return rand_num;
    }
}
/*----- init state ------------*/
void US_init()
{
    US_state_id = init_state_e;
    US_distance = 0 ;
    Us_state_pointer = reading;
}

/*---------send signal -------*/
void US_send_distance_F(uint32_t distance)
{
    extern uint32_t Algo_distance;
    Algo_distance = distance ;
}
/*---------reading_state-----------*/
void reading (uint32_t distance)
{
    US_state_id = reading_state_e;
    US_distance = random_distance_F(45,55,1);
    US_send_distance_F(US_distance);
    Us_state_pointer = reading;
    print("\n - US_reading_state : distance = %d",US_distance);
}

