#include "Linked_list.h"
#include "stdio.h"
#define print(...) (fflush(stdout),fflush(stdin),printf(__VA_ARGS__),fflush(stdout),fflush(stdin))

void main()
{
    LL_node_t* head_pointer;
    LL_init_F(&head_pointer);
    add_node_F(&head_pointer);
    add_node_F(&head_pointer);
    view_all_nodes_F(&head_pointer);
    print("\n done");

}