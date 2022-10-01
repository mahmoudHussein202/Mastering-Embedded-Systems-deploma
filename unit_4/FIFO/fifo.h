#include "stdio.h"

#define element_type int
typedef struct buffer
{
    element_type* head;
    element_type* base;
    element_type* tail;
    int count;
    int length;
}fifo_buffer_t;



typedef enum status
{
    fifo_no_error,
    fifo_full,
    fifo_empty
}fifo_status_t;

void fifo_init_F(fifo_buffer_t* fifo_buffer,element_type arr[],int length);
fifo_status_t push_element_F(fifo_buffer_t* fifo_buffer);
fifo_status_t pop_element_F(fifo_buffer_t* fifo_buffer);
fifo_status_t show_all_elements_F(fifo_buffer_t* fifo_buffer);
