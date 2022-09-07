#include "Linked_list.h"
#include "stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))

void main()
{
    uint32_t choice_temp;
    LL_node_t* head_pointer;
    LL_init_F(&head_pointer);

    while (1)
    {
        print("\n ================ Student data base ======================");
        print("\n 1 - add student. ");
        print("\n 2 - delete student. ");
        print("\n 3 - view all students. ");
        print("\n 4 - delete all. \n\n ");
        print("\n Choose the option number :  ");
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
            view_all_nodes_F(&head_pointer);
            break;
        default:
            print("wrong choice ");
            break;
        }
    }
}