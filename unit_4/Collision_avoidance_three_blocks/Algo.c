#include "stdint.h"
#include "stdio.h"
#include "Algo.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin)) 
uint32_t Algo_distance , Algo_speed , threshold = 50;
Algo_state_t Algo_state_id;

void Algo_init()
{
    Algo_distance = 0;
    Algo_speed = 0;
    Algo_state_pointer = waiting_state;

}
void Algo_recieve_distance()
{
    /* Algo_distance change automatically in this example so no need to this function*/
}
void Algo_send_speed(uint32_t speed)
{
    extern uint32_t DC_speed;
    DC_speed = speed;  
}
void waiting_state()
{   
    Algo_state_id = waiting_state_e;
    Algo_speed = 0 ;
    Algo_send_speed(Algo_speed);
    (Algo_distance >= threshold)?(Algo_state_pointer=driving_state):(Algo_state_pointer=waiting_state);
    print("\n --  Waiting state , speed = %d , distance now = %d ",Algo_speed,Algo_distance);

}

void driving_state()
{   
    Algo_state_id = driving_state_e;
    Algo_speed = 30 ;
    Algo_send_speed(Algo_speed);
    (Algo_distance >= threshold)?(Algo_state_pointer=driving_state):(Algo_state_pointer=waiting_state);
    print("\n --  Waiting state , speed = %d , distance now = %d ",Algo_speed,Algo_distance);

}
