#include "Algo.h"
#include "DC.h"
#include "Us.h"

void setup()
{
    US_init();
    Algo_init();
    motor_init();
}

void main()
{
    /*-------setup---------*/
    int d ;
    setup();
    /*-------loop----------*/
    while (1)
    {
        Us_state_pointer();
        Algo_state_pointer();
        motor_state_pointer();
        for(d=0 ; d < 50000000; d++) ;
    }




}