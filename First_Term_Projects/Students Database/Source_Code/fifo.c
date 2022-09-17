#include "stdio.h"
#include "stdint.h"
#include "fifo.h"
#define print(...)(fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))

fifo_status_t fifo_init(fifo_t* fifo_buffer, student_t *fifo_array,int length )
{
    fifo_buffer->base = fifo_array;
    fifo_buffer->head = fifo_array;
    fifo_buffer->tail = fifo_array;
    fifo_buffer->count = 0 ;
    fifo_buffer->length = length;
    return fifo_no_error;
}

fifo_status_t add_student_manually_F(fifo_t* fifo_buffer)
{
    print("\n Enter First Name : ");
    scanf("%s",&(fifo_buffer->head->First_Name));
    print("\n Enter Last Name : ");
    scanf("%s",&(fifo_buffer->head->Last_Name));
    print("\n Enter ID : ");
    scanf("%d",&(fifo_buffer->head->student_ID));
    print("\n Enter Course 1 ID : ");
    scanf("%d",&(fifo_buffer->head->course_1_ID));
    print("\n Enter Course 2 ID : ");
    scanf("%d",&(fifo_buffer->head->course_2_ID));
    print("\n Enter Course 3 ID : ");
    scanf("%d",&(fifo_buffer->head->course_3_ID));
    print("\n Enter Course 4 ID : ");
    scanf("%d",&(fifo_buffer->head->course_4_ID));
    print("\n Enter Course 5 ID : ");
    scanf("%d",&(fifo_buffer->head->course_5_ID));
    print("\n --------DONE---------- ");
    print("\n -----------------------------------------------------");
    fifo_buffer->head ++ ;
    fifo_buffer->count ++ ;
    return fifo_no_error;
}


fifo_status_t view_all_students_F(fifo_t *fifo_buffer)
{
    if(fifo_buffer->count==0)
        {
            print("\n dataset is empty");
            return fifo_empty;
        }
    else 
        {
            int i = fifo_buffer->count;
            student_t * temp_pointer;
            temp_pointer =(fifo_buffer->base);
            while(!(i==0))
                {
                    print("\n Student Name = %s %s ",temp_pointer->First_Name, temp_pointer->Last_Name);
                    print("\n Student ID = %d ",temp_pointer->student_ID);
                    print("\n Course 1 ID = %d ",temp_pointer->course_1_ID);
                    print("\n Course 2 ID = %d ",temp_pointer->course_2_ID);
                    print("\n Course 3 ID = %d ",temp_pointer->course_3_ID);
                    print("\n Course 4 ID = %d ",temp_pointer->course_4_ID);
                    print("\n Course 5 ID = %d ",temp_pointer->course_5_ID);
                    print("\n -----------------------------------------------------");
                    i--;
                    temp_pointer ++ ;
                }
            
            return fifo_no_error;
        }
}