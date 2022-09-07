#include "Lifo.h"
#include "stddef.h"
#include "stdio.h"

lifo_status_t lifo_init_F(Lifo_buffer_t* lifo_buffer, element_type* buffer_array,uint32_t length){
    if (lifo_buffer ==NULL)
        return lifo_null;
    lifo_buffer->base = buffer_array;
    lifo_buffer->head = buffer_array;
    lifo_buffer->count = 0;
    lifo_buffer->length = length;
    return lifo_no_error;
}
lifo_status_t lifo_push_F(Lifo_buffer_t* lifo_buffer, element_type item){
    if (lifo_buffer ==NULL)
        return lifo_null;
    else if (lifo_is_full_F(lifo_buffer) == lifo_full)
        return lifo_full;
    *(lifo_buffer->head) = item;
    lifo_buffer->count++;
    lifo_buffer->head ++ ;
    return lifo_no_error;
}
lifo_status_t lifo_pop_F(Lifo_buffer_t* lifo_buffer, element_type* item){
    if (lifo_buffer ==NULL)
        return lifo_null;
    else if (lifo_is_empty_F(lifo_buffer) == lifo_empty)
        return lifo_empty;
    if (lifo_is_empty_F(lifo_buffer)== lifo_still_avaliable)
        (lifo_buffer->head)--;
    *(item) = *(lifo_buffer->head);
    (lifo_buffer->count) -- ; 
    return lifo_no_error;
}
lifo_status_t lifo_is_full_F(Lifo_buffer_t* lifo_buffer){
    if (lifo_buffer->count == lifo_buffer->length)
        return lifo_full;
    else 
        return lifo_still_avaliable;
}
lifo_status_t lifo_is_empty_F(Lifo_buffer_t* lifo_buffer){
        if (lifo_buffer->count == 0)
        return lifo_empty;
    else 
        return lifo_still_avaliable;
}

lifo_status_t lifo_view_element_F(Lifo_buffer_t* lifo_buffer){
    int i;
    element_type* temp_head = lifo_buffer->base;
    if (lifo_buffer ==NULL)
    {   printf("\n lifo is null");
        return lifo_null;
    }
    else if (lifo_is_empty_F(lifo_buffer) == lifo_empty){
        printf("\n lifo is empty");
        return lifo_empty;
    }
    for (i=1; i <= lifo_buffer->count ;i++)
    {
        printf("\n %d- value = %d",i,*(temp_head));
        temp_head++;
    }
    return lifo_no_error;
}

