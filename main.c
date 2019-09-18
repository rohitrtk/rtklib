#include "list/rtk_list.h"

#include <stdio.h>

int main(int argc, char** argv)
{
    struct rtklist* list = rtkMallocList();

    for(int i = 0; i < 12; i++)
    {
        rtkListAppend(list, i * 4);
    }
    
    for(int i = 0; i < 12; i++)
    {
        printf("Index %d: %d\n" , i, rtkListGetValueAt(list, i));
    }

    printf("Pop index %d and got %d\n", 3, rtkListPop(list, 3));
    printf("Pop index %d and got %d\n", 3, rtkListPop(list, 3));
    printf("Pop index %d and got %d\n", 3, rtkListPop(list, 3));
    
    for(int i = 0; i < 12; i++)
    {
        printf("Index %d: %d\n" , i, rtkListGetValueAt(list, i));
    }

    rtkFreeList(list);

    return 0;
}