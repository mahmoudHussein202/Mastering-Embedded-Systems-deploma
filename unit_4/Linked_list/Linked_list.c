#include "Linked_list.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))

/*---------initialize the head pointer to Null-------------*/
void LL_init_F(LL_node_t** pointer_to_head)
{
    *(pointer_to_head) = NULL;
}
/*-------add new node ---------------*/
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

/*------------delete a certain node using its' ID ----------------*/
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
/*-------------view all nodes in the list --------------*/
LL_status_t view_all_nodes_F(LL_node_t* pointer_to_head)
{
    if (pointer_to_head== NULL) 
    {
            print("this Linked_list is empty");
            return empty_LL;
    }
    LL_node_t* temporary_LL_pointer;
    temporary_LL_pointer = pointer_to_head;
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


/*-------------print the node of the given index -----------*/
LL_status_t GetNth_F(LL_node_t* pointer_to_head, uint32_t index)
{
    if (pointer_to_head== NULL)
    {   
        print(" \n This Linked List is empty") ;
        return empty_LL;
    }

    int count = 0;
    LL_node_t* temp_pointer;
    temp_pointer = pointer_to_head;
    while (!(count == index))
    {
        temp_pointer = (LL_node_t*)temp_pointer->next_node;
        count ++;
        if (temp_pointer == NULL)
        {
            print("\n Wrong index");
            return error;
        }
    }
        print("\n------------- Student Number %d---------------",(count+1));
        print("\n - Name : %s",temp_pointer->student_data.Name);
        print("\n - ID : %d",temp_pointer->student_data.ID);
        print("\n - Height : %d",temp_pointer->student_data.height);
        temp_pointer = (LL_node_t*)temp_pointer->next_node;
        print("\n-------------------------------------------------------------");
}

/*----------------Length of the list -----------------*/
int Length_of_LL_F(LL_node_t* current_node_pointer)
{
    if (current_node_pointer==NULL)
        return 0;
    else 
        return 1 + Length_of_LL_F((LL_node_t*)current_node_pointer->next_node);  
}


LL_status_t n_node_from_the_End_F(LL_node_t* head_pointer,int n)
{
    int length,needed_node;
    length = Length_of_LL_F(head_pointer);
    needed_node = length - n + 1 ;
    GetNth_F(head_pointer,needed_node-1);
}

LL_status_t middle_node_F(LL_node_t* head_pointer)
{
    uint32_t length,index ;
    length =Length_of_LL_F(head_pointer);
    index = (length/2);
    GetNth_F(head_pointer,index);
}


LL_status_t Reverse_LL_F(LL_node_t** head_pointer)
{
    if (*(head_pointer)== NULL)
        return empty_LL;
    LL_node_t *prev_pointer,*current_pointer,*next_pointer;
    prev_pointer = *(head_pointer);
    current_pointer = (LL_node_t*)((*(head_pointer))->next_node);
    prev_pointer->next_node == NULL;
    while (!(current_pointer == NULL))
    {
        next_pointer = (LL_node_t*)current_pointer->next_node;
        current_pointer->next_node = (uint32_t*)prev_pointer;
        prev_pointer = current_pointer;
        current_pointer = next_pointer;
    }
    *(head_pointer) = prev_pointer;
    return no_error;
}