#include "fifo.h"
#include "stdio.h"
#define print(...) fflush(stdout);fflush(stdin);printf(__VA_ARGS__);fflush(stdout);fflush(stdin);
void fifo_init_F(fifo_buffer_t* fifo_buffer,element_type arr[],int length)

{
    fifo_buffer->base = (element_type*)arr;
    fifo_buffer->head = (element_type*)arr;
    fifo_buffer->tail = (element_type*)arr;
    fifo_buffer->count=0;
    fifo_buffer->length = length;
}


fifo_status_t push_element_F(fifo_buffer_t* fifo_buffer)
{
    if (fifo_buffer->count == fifo_buffer->length)
        return fifo_full;
    
    print("\n   Enter the value num %d : ",fifo_buffer->count);
    element_type temp_value;
    scanf("%d",&temp_value);
    *(fifo_buffer->head)= temp_value;
    if (fifo_buffer->head == fifo_buffer->base + fifo_buffer->length)
        fifo_buffer->head == fifo_buffer->base;
    else 
        fifo_buffer->head++;
    fifo_buffer->count++;
    print("\n-----------------------------------------------")
}
fifo_status_t pop_element_F(fifo_buffer_t* fifo_buffer)
{
    if (fifo_buffer->count ==0)
        return fifo_empty;
    element_type temp_value;
    temp_value = *(fifo_buffer->tail);
    if (fifo_buffer->tail == fifo_buffer->base + fifo_buffer->length)
        fifo_buffer->tail == fifo_buffer->base;
    else 
        fifo_buffer->tail++;
    fifo_buffer->count--;
    print("\n popped item success, it's value = %d ",temp_value);
    print("\n-----------------------------------------------")
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

