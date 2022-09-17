#ifndef _FIFO_H_
#define _FIFO_H_

typedef struct {
    char First_Name[40];
    char Last_Name[40];
    int student_ID;
    int course_1_ID;
    int course_2_ID;
    int course_3_ID;
    int course_4_ID;
    int course_5_ID;
}student_t;

typedef struct {
    int length;
    int count ; 
    student_t *base;
    student_t *head;
    student_t *tail; 
}fifo_t;


typedef enum {
    fifo_full,
    fifo_empty,
    fifo_error,
    fifo_no_error
}fifo_status_t;

fifo_status_t fifo_init(fifo_t* fifo_buffer, student_t *fifo_array,int length);
fifo_status_t add_student_from_file_F(fifo_t* fifo_buffer);//1
fifo_status_t add_student_manually_F(fifo_t* fifo_buffer); //2
fifo_status_t find_student_by_roll_Num_F(fifo_t* fifo_buffer); //3
fifo_status_t find_element_by_first_Name_F(fifo_t* fifo_buffer); //4
fifo_status_t find_students_in_course_F(fifo_t* fifo_buffer); //5
fifo_status_t count_students_F(fifo_t* fifo_buffer); // 6
fifo_status_t delete_student_F(fifo_t* fifo_buffer);//7
fifo_status_t update_student_F(fifo_t* fifo_buffer); //8
fifo_status_t view_all_students_F(fifo_t *fifo_buffer); //9



#endif