#ifndef _FIFO_H_
#define _FIFO_H_
#include "schedular.h"
#define element_type Task_ref*
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

fifo_status_t fifo_init_F(fifo_buffer_t* fifo_buffer,element_type arr[],int length);
fifo_status_t push_element_F(fifo_buffer_t* fifo_buffer , element_type temp_value);
element_type pop_element_F(fifo_buffer_t* fifo_buffer);
fifo_status_t show_all_elements_F(fifo_buffer_t* fifo_buffer);

#endif
