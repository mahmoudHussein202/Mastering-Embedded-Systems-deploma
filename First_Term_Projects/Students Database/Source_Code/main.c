#include "fifo.h"
#include "stdio.h"
#define print(...)(fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))


int main()
{
    fifo_t fifo_buffer;
    student_t fifo_array[100];
    fifo_init(&fifo_buffer,fifo_array,100);  
    int choice ; 
    while(1)
    {
        print("\n ----------STUDENT DATABASE--------------");
        print("\n 1 - Add student from file ");
        print("\n 2 - Add student manually ");
        print("\n 3 - delete student ");
        print("\n 4 - view all students ");
        print("\n 5 - find student by roll number ");
        print("\n 6 - find student by first name ");
        print("\n 7 - Students in a certain course ");
        print("\n 8 - Add student ");
        print("\n 9 - Add student ");
        print("\n\n Enter the option number : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 2:
            add_student_manually_F(&fifo_buffer);
            break;
        case 3 :
            delete_student_F(&fifo_buffer);
            break;
        case 4 : 
            view_all_students_F(&fifo_buffer);
            break;
        case 5 :
            find_student_by_roll_Num_F(&fifo_buffer);
            break;
        case 6 :
            find_element_by_first_Name_F(&fifo_buffer);
            break;
        case 7 :
            find_students_in_course_F(&fifo_buffer);
            break;
        default:
            break;
        }
    }

}