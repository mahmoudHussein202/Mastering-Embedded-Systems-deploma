#include "Linked_list.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))

void LL_init_F(LL_node_t** pointer_to_head)
{
    *(pointer_to_head) = NULL;
}
LL_status_t add_node_F(LL_node_t** pointer_to_head)
{   
    LL_node_t* new_node ;
    LL_node_t* temporary_LL_pointer;
    new_node = (LL_node_t*)malloc(sizeof(LL_node_t));
    print("\n Enter the Name : ");
    gets(new_node->student_data.Name);
    print("\n Enter the ID : ");
    scanf("%d",&(new_node->student_data.ID));
    print("\n Enter the Height : ");
    scanf("%d",&(new_node->student_data.height));
    if (*(pointer_to_head) == NULL)
    {
        *(pointer_to_head)= new_node;
        new_node->next_node == NULL;
    }
    else 
    {   
        temporary_LL_pointer = *(pointer_to_head);
        while (!(temporary_LL_pointer->next_node == NULL))
        {
            temporary_LL_pointer = (LL_node_t*)temporary_LL_pointer->next_node;
        }

        temporary_LL_pointer->next_node = (uint32_t*)new_node;
        new_node->next_node = NULL;
    }
}


LL_status_t delete_node_F(LL_node_t** pointer_to_head)
{
    if (*(pointer_to_head)==NULL)
        return empty_LL;

    int temp_id,counter=0;
    print("\n Enter the ID of student ");
    scanf("%d",&temp_id);
    LL_node_t* current_temp_pointer;
    LL_node_t* previous_temp_pointer;
    current_temp_pointer = *(pointer_to_head);
    previous_temp_pointer= *(pointer_to_head);
    while(!(current_temp_pointer->student_data.ID == temp_id))
    {   
        previous_temp_pointer = current_temp_pointer;
        current_temp_pointer = (LL_node_t*)current_temp_pointer->next_node;
        counter ++;
    }
    if (counter == 0 )
    {
        *(pointer_to_head) = (LL_node_t*)current_temp_pointer->next_node;
        free(current_temp_pointer);
        
    }
    else 
    {
        previous_temp_pointer->next_node = current_temp_pointer->next_node;
        free(current_temp_pointer);

    }
}











LL_status_t view_all_nodes_F(LL_node_t** pointer_to_head)
{
    if (*(pointer_to_head)== NULL) 
    {
            print("this Linked_list is empty");
            return empty_LL;
    }
    LL_node_t* temporary_LL_pointer;
    temporary_LL_pointer = *(pointer_to_head);
    int count = 1; 
    while (!(temporary_LL_pointer == NULL))
    {
        print("\n------------- Student Number %d---------------",count);
        print("\n - Name : %s",temporary_LL_pointer->student_data.Name);
        print("\n - ID : %d",temporary_LL_pointer->student_data.ID);
        print("\n - Height : %d",temporary_LL_pointer->student_data.height);
        temporary_LL_pointer = (LL_node_t*)temporary_LL_pointer->next_node;
        count++;
        print("\n-------------------------------------------------------------");
    }
}



