#include "fifo.h"
#include "stdio.h"
fifo_status_t fifo_init_F(fifo_buffer_t* fifo_buffer,element_type arr[],int length)
{
    fifo_buffer->base = (element_type*)arr;
    fifo_buffer->head = (element_type*)arr;
    fifo_buffer->tail = (element_type*)arr;
    fifo_buffer->count=0;
    fifo_buffer->length = length;
    return fifo_no_error;
}
fifo_status_t push_element_F(fifo_buffer_t* fifo_buffer , element_type task_P)
{
    if (fifo_buffer->count == fifo_buffer->length)
        return fifo_full;

    *(fifo_buffer->head)= task_P;
    if (fifo_buffer->head == fifo_buffer->base + fifo_buffer->length)
        fifo_buffer->head == fifo_buffer->base;
    else 
        fifo_buffer->head++;
    fifo_buffer->count++;
}
element_type pop_element_F(fifo_buffer_t* fifo_buffer)
{
    if (fifo_buffer->count ==0)
        return fifo_empty;
    element_type task_P;
    task_P = *(fifo_buffer->tail);
    if (fifo_buffer->tail == fifo_buffer->base + fifo_buffer->length)
        fifo_buffer->tail == fifo_buffer->base;
    else 
        fifo_buffer->tail++;
    fifo_buffer->count--;
    return task_P;
}
fifo_status_t show_all_elements_F(fifo_buffer_t* fifo_buffer)
{
    if (fifo_buffer->count == 0)
        return fifo_empty;
    element_type* temp_pointer = fifo_buffer->tail;
    for (int i=0;i<fifo_buffer->count;i++)
    {
        print("\n %d- value = %d ",i,*temp_pointer++);
    }


}

