#include "Lifo.h"
#include "stdint.h"
#include "stdio.h"
lifo_status_t status;

Lifo_buffer_t buffer_1;
int main()
{
    element_type buffer_array_1[5];
    char i;
    element_type temp_value;
    lifo_init_F(&buffer_1,buffer_array_1,5);
    // push items to the lifo
    for (i=0;i<7;i++){
        status = lifo_push_F(&buffer_1,i);
        if (status == lifo_no_error)
            printf("\n push succeded , value pushed = %d",i);
        else if (status == lifo_full)
            printf("\n lifo is full, can not add more items");
    }
        // pop items
    for (i=0;i<7;i++){
        status = lifo_pop_F(&buffer_1 , &temp_value);
        if (status == lifo_no_error)
            printf("\n pop succeded , value poped = %d",temp_value);
        else if (status == lifo_empty)
            printf("\n this lifo is empty");
        }


    
    //lifo_view_element_F(&buffer_1);
    return 0;
}