#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "fifo.h"
#include "string.h"
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
    print("\n -----------------DONE-------------------- \n \n ");
    fifo_buffer->head ++ ;
    fifo_buffer->count ++ ;
    return fifo_no_error;
}


fifo_status_t view_all_students_F(fifo_t *fifo_buffer)
{
    if(fifo_buffer->count==0)
        {
            print("\n database is empty");
            return fifo_empty;
        }
    else 
        {
            int i = fifo_buffer->count ;
            student_t * temp_pointer;
            temp_pointer =(fifo_buffer->base);
            while(!(i==0))
                {
                    print("\n -------------student number %d --------- ",(fifo_buffer->count-i+1));
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
fifo_status_t find_student_by_roll_Num_F(fifo_t* fifo_buffer)
{
    if (fifo_buffer->count == 0)
        {
            print("\n database is empty ");
            return fifo_no_error;
        }
    else 
        {
            int temp_ID ;
            student_t *temp_pointer;
            temp_pointer = fifo_buffer->base; 
            print("\n Enter the ID : ");
            scanf("%d",&temp_ID);
            while (!(temp_ID == temp_pointer->student_ID))
                {
                    temp_pointer ++ ;
                }
            print("\n Student Name = %s %s ",temp_pointer->First_Name, temp_pointer->Last_Name);
            print("\n Student ID = %d ",temp_pointer->student_ID);
            print("\n Course 1 ID = %d ",temp_pointer->course_1_ID);
            print("\n Course 2 ID = %d ",temp_pointer->course_2_ID);
            print("\n Course 3 ID = %d ",temp_pointer->course_3_ID);
            print("\n Course 4 ID = %d ",temp_pointer->course_4_ID);
            print("\n Course 5 ID = %d ",temp_pointer->course_5_ID);
            print("\n -----------------------------------------------------");
        }
   
}

fifo_status_t find_element_by_first_Name_F(fifo_t* fifo_buffer)
{
    if (fifo_buffer->count == 0)
        {
            print("\n database is empty ");
            return fifo_no_error;
        }
    else 
        {
            char temp_First_name[40] ;
            student_t *temp_pointer;
            temp_pointer = fifo_buffer->base; 
            print("\n Enter the First Name : ");
            scanf("%s",&temp_First_name);
            while (strcmp(temp_First_name,temp_pointer->First_Name))
                {
                    temp_pointer ++ ;
                }
            print("\n Student Name = %s %s ",temp_pointer->First_Name, temp_pointer->Last_Name);
            print("\n Student ID = %d ",temp_pointer->student_ID);
            print("\n Course 1 ID = %d ",temp_pointer->course_1_ID);
            print("\n Course 2 ID = %d ",temp_pointer->course_2_ID);
            print("\n Course 3 ID = %d ",temp_pointer->course_3_ID);
            print("\n Course 4 ID = %d ",temp_pointer->course_4_ID);
            print("\n Course 5 ID = %d ",temp_pointer->course_5_ID);
            print("\n -----------------------------------------------------\n");
        }
}

fifo_status_t find_students_in_course_F(fifo_t* fifo_buffer)
{
    if (fifo_buffer->count == 0)
    {
        print("\n database is empty ");
        return fifo_no_error;
    }
    int temp_course_ID,temp_count = 0, i = fifo_buffer->count ,j,*temp_course_pointer,student_state ;
    student_t *temp_pointer;
    temp_pointer = fifo_buffer->base;
    print("\n Enter the course ID : ");
    scanf("%d",&temp_course_ID);
    while ( !(i==0))
    {
        temp_course_pointer = &(temp_pointer->course_1_ID);
        student_state = 0;
        for (j=5;j>0;j--)
        {
            if (*temp_course_pointer == temp_course_ID)
            {
                student_state = 1;
            }
            temp_course_pointer++;
        }
        if (student_state == 1)
        {
            temp_count++;
            print("\n %d - %s %s - ID : %d ",temp_count,temp_pointer->First_Name,temp_pointer->Last_Name,temp_pointer->student_ID);
        } 
        temp_pointer++;
        i--;
    }
    if (temp_count == 0)
        {
            print("\n there's no students in this course ");
        }
    return fifo_no_error;
}

fifo_status_t count_students_F(fifo_t* fifo_buffer)
{
    print("\n Number of students : %d ",fifo_buffer->count);
}

fifo_status_t delete_student_F(fifo_t* fifo_buffer)
{
    int temp_ID;
    print("\n Enter the ID of the student : ");
    scanf("%d",&temp_ID);
    student_t* current_pointer;
    student_t* next_pointer;
    current_pointer = fifo_buffer->base;
    while (!(current_pointer->student_ID == temp_ID))
    {
        current_pointer++;
    }
    next_pointer = current_pointer +1; 
    while(1)
    {
        strcpy(current_pointer->First_Name , next_pointer->First_Name);
        strcpy(current_pointer->Last_Name,next_pointer->Last_Name);
        current_pointer->student_ID = next_pointer->student_ID;
        current_pointer->course_1_ID = next_pointer->course_1_ID;
        current_pointer->course_2_ID = next_pointer->course_2_ID;
        current_pointer->course_3_ID = next_pointer->course_3_ID;
        current_pointer->course_4_ID = next_pointer->course_4_ID;
        current_pointer->course_5_ID = next_pointer->course_5_ID;
        current_pointer++;
        next_pointer++;
        if (next_pointer == fifo_buffer->head)
            break;
    }
    fifo_buffer->count--;
    print("\n ------------------ Student is deleated succesfully ---------------- \n\n");
    return fifo_no_error;

}

fifo_status_t update_student_F(fifo_t* fifo_buffer)
{   
    int temp_ID,choice = 0;
    student_t* temp_pointer;
    temp_pointer = fifo_buffer->base;
    print("\n Enter Student ID ");
    scanf("%d",&temp_ID);
    while(!(temp_pointer->student_ID == temp_ID))
    {
        temp_pointer++;
    }
    while (!(choice == 9))
    {
        print("\n Choose what you need to modify : ");
        print("\n   1- first name ");
        print("\n   2- Last name ");
        print("\n   3- student ID ");
        print("\n   4- Course 1 ID ");
        print("\n   5- Course 2 ID ");
        print("\n   6- Course 3 ID ");
        print("\n   7- Course 4 ID ");
        print("\n   8- Course 5 ID ");
        print("\n   9- Exit \n");
        print("\n Enter the Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            print("\nEnter the New first Name : ");
            scanf("%s",&(temp_pointer->First_Name));
            break;
        case 2:
            print("\nEnter the New Last Name : ");
            scanf("%s",&(temp_pointer->Last_Name));
            break;
        case 3:
            print("\nEnter the New Student ID : ");
            scanf("%d",&(temp_pointer->student_ID));
            break;
        case 4:
            print("\nEnter the New Course 1 ID : ");
            scanf("%d",&(temp_pointer->course_1_ID));
            break;
        case 5:
            print("\nEnter the New Course 2 ID : ");
            scanf("%d",&(temp_pointer->course_2_ID));
            break;
        case 6:
            print("\nEnter the New Course 3 ID : ");
            scanf("%d",&(temp_pointer->course_3_ID));
            break;
        case 7:
            print("\nEnter the New Course 4 ID : ");
            scanf("%d",&(temp_pointer->course_4_ID));
            break;
        case 8:
            print("\nEnter the New Course 5 ID : ");
            scanf("%d",&(temp_pointer->course_5_ID));
            break;
        case 9:
            break;
        default:
            print("\n Wrong Choice ");
            break;
        }
        }

    print("\n\n Modification of student ID = %d completed \n \n )",temp_ID );
}

fifo_status_t add_student_from_file_F(fifo_t* fifo_buffer)
{
    FILE *csv_file = fopen("Student_database.csv","r");
    if (csv_file == NULL)
    {
        print("\n Can't read from the file ");
        return fifo_error;
    }
    char line[200],first_line_esc = 0;
    char* word;
    while (fgets(line,sizeof(line),csv_file))
    {   
        if (first_line_esc == 0)
        {
            first_line_esc = 1 ; 
        }
        else 
        {
            word = strtok(line,","); // first name
            strcpy(fifo_buffer->head->First_Name,word);
            word = strtok(NULL,","); //last name
            strcpy(fifo_buffer->head->Last_Name,word);
            word = strtok(NULL,","); // student id 
            fifo_buffer->head->student_ID = atoi(word);
            word = strtok(NULL,","); // course_1_ID
            fifo_buffer->head->course_1_ID = atoi(word);
            word = strtok(NULL,","); // course_2_ID 
            fifo_buffer->head->course_2_ID = atoi(word);
            word = strtok(NULL,","); // course_3_ID 
            fifo_buffer->head->course_3_ID = atoi(word);
            word = strtok(NULL,","); // course_4_ID  
            fifo_buffer->head->course_4_ID = atoi(word);
            word = strtok(NULL,","); // course_5_ID 
            fifo_buffer->head->course_5_ID = atoi(word);
            fifo_buffer->head++;
            fifo_buffer->count++;
        }
    }
}
