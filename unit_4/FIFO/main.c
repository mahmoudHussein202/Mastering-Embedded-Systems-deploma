#include "fifo.h"
#define print(...) fflush(stdout);fflush(stdin);printf(__VA_ARGS__);fflush(stdout);fflush(stdin);

element_type arr[5];

int main()
{
    fifo_buffer_t fifo_buffer;
    fifo_init_F(&fifo_buffer,arr,5);
    while(1)
    {
        int choice; 
        print("\n choose the option :")
        print("\n 1- push element ")
        print("\n 2- pop element  ")
        print("\n 3- show all elements :")

        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push_element_F(&fifo_buffer);
            break;
        case 2: 
            pop_element_F(&fifo_buffer);
            break;
        case 3:
            show_all_elements_F(&fifo_buffer);
            break;
        default:
            print("\n Wrong choice , try again");
            break;
        }
    }
    return 0;
}