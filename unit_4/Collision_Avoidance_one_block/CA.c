#include "CA.h"
#include "stdlib.h"
#define print(...)(fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))
int speed = 0 , distance = 0 , threshold = 50 ;
int random_distance_F(int l , int r , int count)
{
    int i ;
    for (i=0 ; i<count ;i++)
    {
        int rand_num = (rand() % (r-l+1))+1;
        return rand_num;
    }
}


void waiting_state_F()
{
    current_state = waiting_state;
    speed = 0;
    distance = random_distance_F(45,55,1);
    (distance >= threshold  ) ?  (state_pointer = driving_state_F) : (state_pointer = waiting_state_F );
    print("\n  waiting state ,speed = %d , distance now = %d ",speed,distance);
    
}

void driving_state_F()
{
    current_state = driving_state;
    speed = 30 ;
    distance = random_distance_F(45,55,1);
    (distance >= threshold) ? (state_pointer = driving_state_F):(state_pointer = waiting_state_F);
    print("\n  driving state ,speed = %d , distance now = %d ",speed,distance);
}