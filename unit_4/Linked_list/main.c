#include "Linked_list.h"
#include "stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))

void main()
{
    uint32_t choice_temp,index,count=0;
    LL_node_t* head_pointer;
    LL_init_F(&head_pointer);

    while (1)
    {
        print("\n ================ Student data base ======================");
        print("\n 1 - add student. ");
        print("\n 2 - delete student. ");
        print("\n 3 - view all students. ");
        print("\n 4 - view a certain index. ");
        print("\n 5 - number of elements in the List.");
        print("\n 6 - nth node from the end.");
        print("\n 7 - print the middle node");
        print("\n 8 - reverse the linked list");       
        print("\n\n Choose the option number :  ");
        scanf("%d",&choice_temp);
        switch (choice_temp)
        {
        case 1:
            add_node_F(&head_pointer);
            break;
        case 2:
            delete_node_F(&head_pointer);
            break;
        case 3 : 
            view_all_nodes_F(head_pointer);
            break;
        case 4 : 
            print("Enter the index :");
            scanf("%d",&index);
            GetNth_F(head_pointer,index);
            break;
        case 5 : 
            count = Length_of_LL_F(head_pointer);
            print("\n----------------------------------------");
            print("\n number of elements : %d ",count);
            print("\n----------------------------------------");
            break;
        case 6 : 
            print("Enter node number from the end :");
            scanf("%d",&index);
            n_node_from_the_End_F(head_pointer,index);
            break;
        case 7 : 
            middle_node_F(head_pointer);
            break;
        case 8 : 
            Reverse_LL_F(&head_pointer);
            break;
        default:
            print("wro1ng choice ");
            break;
        }
    }
}