#include "fifo.h"


int main()
{
    fifo_t fifo_buffer;
    student_t fifo_array[100];
    fifo_init(&fifo_buffer,fifo_array,100);  
    add_student_manually_F(&fifo_buffer);
    add_student_manually_F(&fifo_buffer);
    view_all_students_F(&fifo_buffer);
}