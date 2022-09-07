#ifndef _LIFO_H_
#define _LIFO_H

#include "stdint.h"
#define element_type char

typedef struct
{
    uint32_t length;
    uint32_t count;
    element_type* head;
    element_type* base;
}Lifo_buffer_t;

typedef enum {
    lifo_null,
    lifo_no_error,
    lifo_full,
    lifo_still_avaliable,
    lifo_empty
} lifo_status_t ;

lifo_status_t lifo_init_F(Lifo_buffer_t* lifo_buffer, element_type* buffer_array,uint32_t length);
lifo_status_t lifo_push_F(Lifo_buffer_t* lifo_buffer, element_type item);
lifo_status_t lifo_pop_F(Lifo_buffer_t* lifo_buffer, element_type* item);
lifo_status_t lifo_is_full_F(Lifo_buffer_t* lifo_buffer);
lifo_status_t lifo_is_empty_F(Lifo_buffer_t* lifo_buffer);
lifo_status_t lifo_view_element_F(Lifo_buffer_t* lifo_buffer);

#endif