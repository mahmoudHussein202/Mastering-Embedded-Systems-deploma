#include "stdint.h"

typedef struct{
    char Name[40];
    uint32_t height;
    uint32_t ID;
}effective_data;
typedef struct 
{
    effective_data student_data;
    uint32_t* next_node;
}LL_node_t;
typedef enum {
    no_error,
    error,
    empty_LL
}LL_status_t;
//-----------APIs---------------
void LL_init_F(LL_node_t** pointer_to_head);
LL_status_t add_node_F(LL_node_t** pointer_to_head);
LL_status_t view_all_nodes_F(LL_node_t** pointer_to_head);
LL_status_t delete_node(LL_node_t** pointer_to_head, int ID);