#include "list/rtk_list.h"
#include "array/rtk_array.h"

#include <stdio.h>

#define LAZYFOR(loopNum, block) for(int i = 0; i < loopNum; ++i) { block; }

void testList()
{
    rtklist* list = rtkMallocList();

    for(int i = 0; i < 12; i++)
    {
        list->append(list, i * 4);
    }
    
    for(int i = 0; i < 12; i++)
    {
        printf("Index %d: %d\n" , i, list->get(list, i));
    }

    printf("Pop index %d and got %d\n", 3, list->pop(list, 3));
    printf("Pop index %d and got %d\n", 3, list->pop(list, 3));
    printf("Pop index %d and got %d\n", 3, list->pop(list, 3));
    
    for(int i = 0; i < 12; i++)
    {
        printf("Index %d: %d\n" , i, list->get(list, i));
    }

    rtkFreeList(list);
}

void testArray()
{
    rtkarray* array = rtkMallocArray(10);

    for(int i = 0; i < array->size(array); ++i)
    {
        array->set(array, i, i * 4);
    }

    for(int i = 0; i < array->size(array); ++i)
    {
        printf("%d\n", array->get(array, i));
    }

    rtkFreeArray(array);
}

int main(int argc, char** argv)
{
    testList();
    testArray();

    return 0;
}