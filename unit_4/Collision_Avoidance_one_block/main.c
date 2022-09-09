#include "CA.h"


void setup()
{
    state_pointer = waiting_state_F;
}

void main ()
{
    /*setup*/
    int delay;
    setup();
    /*loop*/

    while (1)
    {
        state_pointer();
        for (delay = 0 ; delay <= 5000; delay ++);
    }




}